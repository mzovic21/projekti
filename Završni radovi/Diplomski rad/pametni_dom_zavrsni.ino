/*
  ESP32 program za model pametnog doma.
  Isti podaci koriste se u mobilnoj aplikaciji i Unity digitalnom blizancu

  Raspored pinova na modelu:
    GPIO25 - LED Spavaca soba 1
    GPIO26 - LED WC
    GPIO27 - LED Spavaca soba 2
    GPIO19 - aktivna zujalica
    GPIO21 - DHT11
    GPIO34 - fotootpornik
    GPIO18 - servo SG90
    GPIO23 - L298N IN1
    GPIO22 - L298N IN2
    GPIO33 - tipkalo zvona
*/

#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
#include <ESP32Servo.h>

// Wi-Fi postavke

// Za prezentaciju se koristi mreza koju stvara ESP32 jer ne ovisi o dostupnom Wi-Fiju
// Ako se USE_HOME_WIFI postavi na true, prvo se pokusava spojiti na zadanu mrezu
const bool USE_HOME_WIFI = false;

const char* HOME_WIFI_SSID = "UPISI_NAZIV_WIFI_MREZE";
const char* HOME_WIFI_PASSWORD = "UPISI_WIFI_LOZINKU";

const char* AP_NAME = "PametniDom-ESP32";
const char* AP_PASSWORD = "PametniDom32";  // najmanje 8 znakova

// Pinovi

const int LED_BEDROOM_1_PIN = 25;
const int LED_WC_PIN = 26;
const int LED_BEDROOM_2_PIN = 27;

const int BUZZER_PIN = 19;
const int DHT_PIN = 21;
const int LDR_PIN = 34;
const int SERVO_PIN = 18;
const int FAN_IN1_PIN = 23;
const int FAN_IN2_PIN = 22;
const int DOORBELL_BUTTON_PIN = 33;

#define DHT_TYPE DHT11

// Postavke automatizacije

// Osvjetljenje na mjestu prezentacije nije uvijek isto. Zato se prvih pet
// sekundi izmjeri pocetna vrijednost, a ostale se usporeduju s njom
// Odvojeni pragovi i potvrda od dvije sekunde uvedeni su jer su se bez toga
// LED diode znale brzo paliti i gasiti oko granicne vrijednosti
const float LDR_DARK_RATIO = 0.50f;
const float LDR_DAY_RATIO = 0.70f;
const int LDR_MIN_VALID_BASELINE = 50;
const unsigned long LDR_CALIBRATION_DURATION_MS = 5000;
const unsigned long LDR_CONDITION_CONFIRMATION_MS = 2000;

// Prvo valjano DHT11 ocitanje uzima se kao stanje prostorije prije testa
// Pragovi su odabrani prema mjerenju u kojem su vrijednosti porasle
// s 26,4 na 27,4 C i s 57 na 67 % vlaznosti.
const float FAN_ON_TEMPERATURE_RISE = 1.0f;
const float FAN_ON_HUMIDITY_RISE = 10.0f;

// Za gasenje se koriste nizi pragovi kako ventilator ne bi stalno mijenjao stanje
const float FAN_OFF_TEMPERATURE_RISE = 0.5f;
const float FAN_OFF_HUMIDITY_RISE = 5.0f;

// Kutovi su prilagodeni polozaju serva i vrata na fizickom modelu
const int DOOR_CLOSED_ANGLE = 45;
const int DOOR_OPEN_ANGLE = 135;

const unsigned long DOORBELL_DURATION_MS = 1000;
const unsigned long DHT_INTERVAL_MS = 2500;
const unsigned long LDR_INTERVAL_MS = 250;
const unsigned long BUTTON_DEBOUNCE_MS = 50;

// Objekti i trenutno stanje sustava

DHT dht(DHT_PIN, DHT_TYPE);
Servo doorServo;

// ESP32 ovdje radi kao mali web posluzitelj. Port 80 je uobicajeni HTTP port,
// pa se adresama moze pristupiti iz preglednika, mobilne aplikacije i Unityja
WebServer server(80);

enum FanMode
{
  FAN_AUTOMATIC,
  FAN_MANUAL
};

bool bedroom1LightOn = false;
bool wcLightOn = false;
bool bedroom2LightOn = false;

bool doorOpen = false;
bool fanOn = false;
// Nakon pokretanja radi automatika. Klik na gumb ventilatora prebacuje
// upravljanje u rucni nacin, cime se omogucuje zasebno testiranje motora
FanMode fanMode = FAN_AUTOMATIC;

bool manualBuzzerOn = false;
bool doorbellActive = false;
unsigned long doorbellEndTime = 0;

float temperatureC = NAN;
float humidityPercent = NAN;
float baseTemperatureC = NAN;
float baseHumidityPercent = NAN;
bool fanBaselineInitialized = false;
int lightRaw = 0;
int lightPercent = 0;
int lightBaseline = 0;
int lightDarkThreshold = 0;
int lightDayThreshold = 0;
bool isDark = false;
bool lightCalibrated = false;
bool lightSensorError = false;
bool pendingLightCondition = false;
bool pendingDarkState = false;

unsigned long lightCalibrationStartTime = 0;
unsigned long lightCalibrationSum = 0;
unsigned int lightCalibrationSamples = 0;
unsigned long pendingLightConditionStartTime = 0;

unsigned long lastDhtReadTime = 0;
unsigned long lastLdrReadTime = 0;

int lastButtonReading = HIGH;
int stableButtonState = HIGH;
unsigned long lastButtonChangeTime = 0;

// Funkcije za upravljanje izlazima

void setBedroom1Light(bool turnOn)
{
  bedroom1LightOn = turnOn;
  digitalWrite(LED_BEDROOM_1_PIN, turnOn ? HIGH : LOW);
}

void setWCLight(bool turnOn)
{
  wcLightOn = turnOn;
  digitalWrite(LED_WC_PIN, turnOn ? HIGH : LOW);
}

void setBedroom2Light(bool turnOn)
{
  bedroom2LightOn = turnOn;
  digitalWrite(LED_BEDROOM_2_PIN, turnOn ? HIGH : LOW);
}

void setAllLights(bool turnOn)
{
  setBedroom1Light(turnOn);
  setWCLight(turnOn);
  setBedroom2Light(turnOn);
}

void setFan(bool turnOn)
{
  fanOn = turnOn;

  if (turnOn)
  {
    digitalWrite(FAN_IN1_PIN, HIGH);
    digitalWrite(FAN_IN2_PIN, LOW);
  }
  else
  {
    digitalWrite(FAN_IN1_PIN, LOW);
    digitalWrite(FAN_IN2_PIN, LOW);
  }
}

void setDoor(bool open)
{
  doorOpen = open;
  doorServo.write(open ? DOOR_OPEN_ANGLE : DOOR_CLOSED_ANGLE);
}

void updateBuzzerOutput()
{
  digitalWrite(BUZZER_PIN, (manualBuzzerOn || doorbellActive) ? HIGH : LOW);
}

void startDoorbell()
{
  doorbellActive = true;
  doorbellEndTime = millis() + DOORBELL_DURATION_MS;
  updateBuzzerOutput();
  Serial.println(F("Zvono aktivirano na 1 sekundu."));
}

// Usporedba vremena koristi se za zvono bez zaustavljanja ostatka programa
bool timeReached(unsigned long targetTime)
{
  return (long)(millis() - targetTime) >= 0;
}

void updateDoorbell()
{
  if (doorbellActive && timeReached(doorbellEndTime))
  {
    doorbellActive = false;
    updateBuzzerOutput();
  }
}

// Ocitavanje senzora i automatizacija

int readAverageLight()
{
  long sum = 0;
  const int sampleCount = 8;

  for (int i = 0; i < sampleCount; i++)
  {
    sum += analogRead(LDR_PIN);
    delayMicroseconds(250);
  }

  return sum / sampleCount;
}

void startLightCalibration()
{
  setAllLights(false);

  lightCalibrated = false;
  lightSensorError = false;
  pendingLightCondition = false;
  isDark = false;
  lightPercent = 0;

  lightCalibrationStartTime = millis();
  lightCalibrationSum = 0;
  lightCalibrationSamples = 0;

  Serial.println(F("Kalibracija svjetla pokrenuta."));
  Serial.println(F("Fotootpornik ostavi otkriven, a osvjetljenje prostorije normalno."));
}

void finishLightCalibration()
{
  if (lightCalibrationSamples == 0)
  {
    return;
  }

  lightBaseline = lightCalibrationSum / lightCalibrationSamples;

  // Testiranjem je utvrdeno da vrijednost blizu nule upucuje na pogresan spoj
  // ili neuspjelu kalibraciju, U tom se slucaju automatska rasvjeta ne pokrece
  if (lightBaseline < LDR_MIN_VALID_BASELINE)
  {
    lightBaseline = 0;
    lightPercent = 0;
    lightDarkThreshold = 0;
    lightDayThreshold = 0;
    lightCalibrated = false;
    lightSensorError = true;
    pendingLightCondition = false;
    isDark = false;
    setAllLights(false);

    Serial.println(F("GRESKA: kalibracija svjetla nije uspjela."));
    Serial.println(F("Ponovno otvori /calibrate-light."));
    return;
  }

  lightDarkThreshold = (int)(lightBaseline * LDR_DARK_RATIO);
  lightDayThreshold = (int)(lightBaseline * LDR_DAY_RATIO);

  if (lightDayThreshold <= lightDarkThreshold)
  {
    lightDayThreshold = lightDarkThreshold + 1;
  }
  lightPercent = constrain(
    (int)(((long)lightRaw * 100L + lightBaseline / 2) / lightBaseline),
    0,
    100
  );

  lightCalibrated = true;
  lightSensorError = false;
  pendingLightCondition = false;
  isDark = false;

  Serial.println(F("Kalibracija svjetla zavrsena."));
  Serial.print(F("Baza: "));
  Serial.print(lightBaseline);
  Serial.print(F(" | MRAK ispod: "));
  Serial.print(lightDarkThreshold);
  Serial.print(F(" | DAN iznad: "));
  Serial.println(lightDayThreshold);
}

void updateLightSensor()
{
  if (millis() - lastLdrReadTime < LDR_INTERVAL_MS)
  {
    return;
  }

  lastLdrReadTime = millis();

  lightRaw = readAverageLight();

  if (lightSensorError)
  {
    lightPercent = 0;
    return;
  }

  if (!lightCalibrated)
  {
    lightCalibrationSum += lightRaw;
    lightCalibrationSamples++;

    if (millis() - lightCalibrationStartTime >=
        LDR_CALIBRATION_DURATION_MS)
    {
      finishLightCalibration();
    }

    return;
  }

  lightPercent = constrain(
    (int)(((long)lightRaw * 100L + lightBaseline / 2) / lightBaseline),
    0,
    100
  );

  bool requestedDarkState = isDark;

  if (!isDark && lightRaw <= lightDarkThreshold)
  {
    requestedDarkState = true;
  }
  else if (isDark && lightRaw >= lightDayThreshold)
  {
    requestedDarkState = false;
  }

  if (requestedDarkState == isDark)
  {
    pendingLightCondition = false;
    return;
  }

  if (!pendingLightCondition || pendingDarkState != requestedDarkState)
  {
    pendingLightCondition = true;
    pendingDarkState = requestedDarkState;
    pendingLightConditionStartTime = millis();
    return;
  }

  if (millis() - pendingLightConditionStartTime <
      LDR_CONDITION_CONFIRMATION_MS)
  {
    return;
  }

  isDark = requestedDarkState;
  pendingLightCondition = false;
  setAllLights(isDark);

  Serial.print(F("Svjetlost: "));
  Serial.print(lightRaw);
  Serial.print(F(" | Relativno: "));
  Serial.print(lightPercent);
  Serial.print(F(" % | Uvjeti: "));
  Serial.println(isDark ? F("MRAK - rasvjeta ukljucena")
                        : F("DAN - rasvjeta iskljucena"));
}

void updateAutomaticFan()
{
  if (fanMode != FAN_AUTOMATIC ||
      !fanBaselineInitialized ||
      isnan(temperatureC) ||
      isnan(humidityPercent))
  {
    return;
  }

  bool temperatureReachedOnThreshold =
    temperatureC >= baseTemperatureC + FAN_ON_TEMPERATURE_RISE;

  bool humidityReachedOnThreshold =
    humidityPercent >= baseHumidityPercent + FAN_ON_HUMIDITY_RISE;

  bool temperatureReturnedBelowOffThreshold =
    temperatureC <= baseTemperatureC + FAN_OFF_TEMPERATURE_RISE;

  bool humidityReturnedBelowOffThreshold =
    humidityPercent <= baseHumidityPercent + FAN_OFF_HUMIDITY_RISE;

  // Porast temperature ili vlaznosti ukljucuje ventilator
  if (!fanOn &&
      (temperatureReachedOnThreshold || humidityReachedOnThreshold))
  {
    setFan(true);
    Serial.println(F("Automatika: ventilator ukljucen."));
  }
  // Iskljucuje se tek kada se obje vrijednosti vrate blizu pocetnih
  else if (fanOn &&
           temperatureReturnedBelowOffThreshold &&
           humidityReturnedBelowOffThreshold)
  {
    setFan(false);
    Serial.println(F("Automatika: ventilator iskljucen."));
  }
}

void updateDHT11()
{
  if (millis() - lastDhtReadTime < DHT_INTERVAL_MS)
  {
    return;
  }

  lastDhtReadTime = millis();

  float newHumidity = dht.readHumidity();
  float newTemperature = dht.readTemperature();

  if (isnan(newHumidity) || isnan(newTemperature))
  {
    Serial.println(F("Pogreska pri ocitavanju DHT11 senzora."));
    return;
  }

  humidityPercent = newHumidity;
  temperatureC = newTemperature;

  if (!fanBaselineInitialized)
  {
    baseTemperatureC = temperatureC;
    baseHumidityPercent = humidityPercent;
    fanBaselineInitialized = true;

    Serial.print(F("Baza ventilatora: "));
    Serial.print(baseTemperatureC, 1);
    Serial.print(F(" C | "));
    Serial.print(baseHumidityPercent, 0);
    Serial.println(F(" %"));
  }

  updateAutomaticFan();

  Serial.print(F("Temperatura: "));
  Serial.print(temperatureC, 1);
  Serial.print(F(" C | Vlaznost: "));
  Serial.print(humidityPercent, 0);
  Serial.println(F(" %"));
}

void updatePhysicalDoorbellButton()
{
  int reading = digitalRead(DOORBELL_BUTTON_PIN);

  if (reading != lastButtonReading)
  {
    lastButtonReading = reading;
    lastButtonChangeTime = millis();
  }

  if (millis() - lastButtonChangeTime >= BUTTON_DEBOUNCE_MS &&
      reading != stableButtonState)
  {
    stableButtonState = reading;

    if (stableButtonState == LOW)
    {
      startDoorbell();
    }
  }
}

// HTTP komunikacija s mobilnom aplikacijom i Unityjem

// Tok komunikacije je uvijek slican:
// 1. aplikacija ili Unity posalju GET zahtjev na adresu ESP32-a
// 2. funkcija povezana s tom adresom procita ili promijeni stanje
// 3. ESP32 vrati JSON s trenutnim podacima
// 4. aplikacija i Unity iz tog JSON-a osvjeze svoj prikaz

const char* jsonBool(bool value)
{
  return value ? "true" : "false";
}

String jsonFloatOrNull(float value, int decimals)
{
  if (isnan(value))
  {
    return "null";
  }

  return String(value, decimals);
}

void addCorsHeaders()
{
  // Ova zaglavlja dopustaju da Unity ili web preglednik prihvate odgovor
  // i sprjecavaju spremanje starog statusa u predmemoriju.
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
  server.sendHeader("Cache-Control", "no-store");
}

String buildStatusJson()
{
  // JSON je tekstualni zapis u obliku "naziv":vrijednost. Na taj nacin svi
  // klijenti dobivaju iste nazive, primjerice temperature, fan i doorOpen.
  int activeLights = (bedroom1LightOn ? 1 : 0) +
                     (wcLightOn ? 1 : 0) +
                     (bedroom2LightOn ? 1 : 0);

  float temperatureDelta = fanBaselineInitialized
                             ? temperatureC - baseTemperatureC
                             : NAN;
  float humidityDelta = fanBaselineInitialized
                          ? humidityPercent - baseHumidityPercent
                          : NAN;

  String json;
  json.reserve(800);
  json += "{";
  json += "\"temperature\":" + jsonFloatOrNull(temperatureC, 1) + ",";
  json += "\"humidity\":" + jsonFloatOrNull(humidityPercent, 0) + ",";
  json += "\"temperatureBase\":" + jsonFloatOrNull(baseTemperatureC, 1) + ",";
  json += "\"humidityBase\":" + jsonFloatOrNull(baseHumidityPercent, 0) + ",";
  json += "\"temperatureDelta\":" + jsonFloatOrNull(temperatureDelta, 1) + ",";
  json += "\"humidityDelta\":" + jsonFloatOrNull(humidityDelta, 0) + ",";
  json += "\"lightRaw\":" + String(lightRaw) + ",";
  json += "\"lightPercent\":" + String(lightPercent) + ",";
  json += "\"lightBaseline\":" + String(lightBaseline) + ",";
  json += "\"lightDarkThreshold\":" + String(lightDarkThreshold) + ",";
  json += "\"lightDayThreshold\":" + String(lightDayThreshold) + ",";
  json += "\"lightCalibrated\":" + String(jsonBool(lightCalibrated)) + ",";
  json += "\"lightSensorError\":" + String(jsonBool(lightSensorError)) + ",";
  String lightCondition = lightSensorError
                            ? "GREŠKA SENZORA"
                            : (!lightCalibrated
                                ? "KALIBRACIJA"
                                : (isDark ? "MRAK" : "DAN"));
  json += "\"lightCondition\":\"" + lightCondition + "\",";
  json += "\"bedroom1\":" + String(jsonBool(bedroom1LightOn)) + ",";
  json += "\"wc\":" + String(jsonBool(wcLightOn)) + ",";
  json += "\"bedroom2\":" + String(jsonBool(bedroom2LightOn)) + ",";
  json += "\"activeLights\":" + String(activeLights) + ",";
  json += "\"fan\":" + String(jsonBool(fanOn)) + ",";
  json += "\"fanMode\":\"" + String(fanMode == FAN_AUTOMATIC ? "auto" : "manual") + "\",";
  json += "\"doorOpen\":" + String(jsonBool(doorOpen)) + ",";
  json += "\"buzzer\":" + String(jsonBool(manualBuzzerOn || doorbellActive)) + ",";
  json += "\"doorbell\":" + String(jsonBool(doorbellActive)) + ",";
  json += "\"uptimeMs\":" + String(millis());
  json += "}";
  return json;
}

void sendStatusJson()
{
  // Kod 200 oznacava da je zahtjev uspjesno obraden.
  addCorsHeaders();
  server.send(200, "application/json; charset=utf-8", buildStatusJson());
}

bool parseOnOff(const String& state, bool& turnOn)
{
  if (state == "on" || state == "1" || state == "true")
  {
    turnOn = true;
    return true;
  }

  if (state == "off" || state == "0" || state == "false")
  {
    turnOn = false;
    return true;
  }

  return false;
}

void handleStatus()
{
  // /status samo cita stanje i ne upravlja uredajima
  sendStatusJson();
}

void handleControl()
{
  // Primjer: /control?device=wc&state=on
  // device govori kojim se uredajem upravlja, a state zeljeno stanje
  if (!server.hasArg("device") || !server.hasArg("state"))
  {
    addCorsHeaders();
    server.send(400, "application/json; charset=utf-8",
                "{\"error\":\"Nedostaju parametri device i state.\"}");
    return;
  }

  String device = server.arg("device");
  String state = server.arg("state");
  device.toLowerCase();
  state.toLowerCase();

  bool turnOn = false;
  bool validOnOff = parseOnOff(state, turnOn);

  if (device == "bedroom1" && validOnOff)
  {
    setBedroom1Light(turnOn);
  }
  else if (device == "wc" && validOnOff)
  {
    setWCLight(turnOn);
  }
  else if (device == "bedroom2" && validOnOff)
  {
    setBedroom2Light(turnOn);
  }
  else if (device == "fan" && state == "auto")
  {
    fanMode = FAN_AUTOMATIC;
    updateAutomaticFan();
  }
  else if (device == "fan" && validOnOff)
  {
    fanMode = FAN_MANUAL;
    setFan(turnOn);
  }
  else if (device == "door" && validOnOff)
  {
    setDoor(turnOn);
  }
  else if (device == "buzzer" && validOnOff)
  {
    manualBuzzerOn = turnOn;
    updateBuzzerOutput();
  }
  else
  {
    addCorsHeaders();
    server.send(400, "application/json; charset=utf-8",
                "{\"error\":\"Nepoznat uredaj ili stanje.\"}");
    return;
  }

  sendStatusJson();
}

void handleDoorbell()
{
  startDoorbell();
  sendStatusJson();
}

void handleCalibrateLight()
{
  startLightCalibration();
  sendStatusJson();
}

void handleOptions()
{
  // OPTIONS je pomocni zahtjev koji preglednik moze poslati prije glavnog GET-a
  addCorsHeaders();
  server.send(204, "text/plain", "");
}

void handleRoot()
{
  String message;
  message.reserve(900);
  message += "PAMETNI DOM - ESP32\n\n";
  message += "Status:\n/status\n\n";
  message += "Upravljanje:\n";
  message += "/control?device=bedroom1&state=on\n";
  message += "/control?device=wc&state=off\n";
  message += "/control?device=bedroom2&state=on\n";
  message += "/control?device=fan&state=on|off|auto\n";
  message += "/control?device=door&state=on|off\n";
  message += "/control?device=buzzer&state=on|off\n\n";
  message += "Zvono:\n/doorbell\n\n";
  message += "Ponovna kalibracija svjetla:\n/calibrate-light\n\n";
  message += "Napomena: lightPercent je relativna vrijednost prema kalibriranoj bazi, a ne lux.";

  addCorsHeaders();
  server.send(200, "text/plain; charset=utf-8", message);
}

void handleNotFound()
{
  // Kod 404 vraca se ako trazena adresa nije registrirana ispod
  addCorsHeaders();
  server.send(404, "application/json; charset=utf-8",
              "{\"error\":\"Putanja nije pronadena.\"}");
}

void configureWebServer()
{
  // server.on povezuje URL putanju s funkcijom koja je obraduje
  // Na primjer, zahtjev /status poziva handleStatus()
  server.on("/", HTTP_GET, handleRoot);
  server.on("/status", HTTP_GET, handleStatus);
  server.on("/control", HTTP_GET, handleControl);
  server.on("/doorbell", HTTP_GET, handleDoorbell);
  server.on("/calibrate-light", HTTP_GET, handleCalibrateLight);

  server.on("/status", HTTP_OPTIONS, handleOptions);
  server.on("/control", HTTP_OPTIONS, handleOptions);
  server.on("/doorbell", HTTP_OPTIONS, handleOptions);
  server.on("/calibrate-light", HTTP_OPTIONS, handleOptions);

  server.onNotFound(handleNotFound);

  // Nakon begin() ESP32 pocinje prihvacati HTTP zahtjeve
  server.begin();
  Serial.println(F("HTTP posluzitelj pokrenut."));
}

void startWiFi()
{
  // WIFI_STA znaci da se ESP32 spaja na postojecu mrezu kao i drugi uredaji
  // Ako spajanje ne uspije u 15 sekundi, nastavlja se s vlastitom AP mrezom
  if (USE_HOME_WIFI)
  {
    WiFi.mode(WIFI_STA);
    WiFi.begin(HOME_WIFI_SSID, HOME_WIFI_PASSWORD);
    Serial.print(F("Spajanje na kucni Wi-Fi"));

    unsigned long connectionStart = millis();

    while (WiFi.status() != WL_CONNECTED && millis() - connectionStart < 15000)
    {
      delay(250);
      Serial.print('.');
    }

    Serial.println();

    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.print(F("ESP32 IP adresa: http://"));
      Serial.println(WiFi.localIP());
      return;
    }

    Serial.println(F("Kucni Wi-Fi nije dostupan. Pokrecem vlastitu mrezu."));
    WiFi.disconnect(true);
    delay(100);
  }

  // WIFI_AP znaci da ESP32 sam stvara mrezu PametniDom-ESP32
  // U tom nacinu njegova adresa je 192.168.4.1, sto koriste aplikacija i Unity
  WiFi.mode(WIFI_AP);

  if (!WiFi.softAP(AP_NAME, AP_PASSWORD))
  {
    Serial.println(F("Pogreska pri pokretanju ESP32 Wi-Fi mreze."));
    return;
  }

  Serial.print(F("Spoji se na Wi-Fi mrezu: "));
  Serial.println(AP_NAME);
  Serial.print(F("Lozinka: "));
  Serial.println(AP_PASSWORD);
  Serial.print(F("ESP32 adresa: http://"));
  Serial.println(WiFi.softAPIP());
}

// Pokretanje programa

void setup()
{
  Serial.begin(115200);

  pinMode(LED_BEDROOM_1_PIN, OUTPUT);
  pinMode(LED_WC_PIN, OUTPUT);
  pinMode(LED_BEDROOM_2_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(FAN_IN1_PIN, OUTPUT);
  pinMode(FAN_IN2_PIN, OUTPUT);
  pinMode(DOORBELL_BUTTON_PIN, INPUT_PULLUP);
  pinMode(LDR_PIN, INPUT);

  // Pri ukljucivanju modela svi izlazi najprije ostaju ugaseni
  setAllLights(false);
  setFan(false);
  manualBuzzerOn = false;
  doorbellActive = false;
  updateBuzzerOutput();

  analogReadResolution(12);
  dht.begin();

  ESP32PWM::allocateTimer(0);
  doorServo.setPeriodHertz(50);
  doorServo.attach(SERVO_PIN, 500, 2400);
  setDoor(false);

  lastButtonReading = digitalRead(DOORBELL_BUTTON_PIN);
  stableButtonState = lastButtonReading;
  lastDhtReadTime = millis();

  startWiFi();

  // Web posluzitelj pokrece se tek nakon Wi-Fi mreze jer bez mreze klijenti
  // ne mogu poslati zahtjev ESP32-u
  configureWebServer();
  startLightCalibration();

  Serial.println(F("Pametni dom je pokrenut."));
}

void loop()
{
  // handleClient provjerava je li stigao novi zahtjev i poziva odgovarajucu
  // handle funkciju registriranu u configureWebServer()
  server.handleClient();
  updatePhysicalDoorbellButton();
  updateDoorbell();
  updateLightSensor();
  updateDHT11();

  // Kratka pauza je dovoljna za Wi-Fi, a ne usporava ocitavanje senzora
  delay(2);
}
