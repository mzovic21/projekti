using System;
using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;

public class ESP32Connection : MonoBehaviour
{
    // Ova skripta je veza izmedu Unity scene i ESP32-a
    // Unity jednom u sekundi cita /status, a klikove salje preko /control
    // Ako ESP32 nije dostupan, DigitalTwinController nastavlja raditi lokalno

    [Serializable]
    private class ESP32Status
    {
        // Nazivi polja moraju biti jednaki nazivima koje ESP32 salje u JSON-u
        // JsonUtility tada automatski upisuje primljene vrijednosti u ovaj objekt
        public float temperature;
        public float humidity;

        public int lightPercent;
        public string lightCondition;

        public bool bedroom1;
        public bool wc;
        public bool bedroom2;

        public bool fan;
        public bool doorOpen;
        public bool buzzer;
    }

    [Header("Povezivanje")]
    // Ovo je adresa ESP32-a kada on stvara mrezu PametniDom-ESP32
    [SerializeField] private string baseUrl = "http://192.168.4.1";

    // Razmak izmedu dva citanja statusa, izrazen u sekundama
    [SerializeField] private float refreshInterval = 1f;

    [Header("Digitalni blizanac")]
    [SerializeField] private DigitalTwinController digitalTwinController;

    [Header("Prikaz veze")]
    [SerializeField] private TMP_Text connectionText;

    [SerializeField]
    private Color connectedColor =
        new Color32(77, 139, 112, 255);

    [SerializeField]
    private Color disconnectedColor =
        new Color32(217, 97, 122, 255);

    private bool hasCheckedConnection;
    private bool wasConnected;

    // Dok se salje naredba, privremeno se zaustavlja redovno citanje statusa
    // Time se izbjegavaju dva HTTP zahtjeva u istom trenutku
    private bool commandInProgress;

    // Veza se smatra aktivnom tek nakon barem jednog uspjesnog odgovora ESP32-a
    public bool IsConnected =>
        isActiveAndEnabled &&
        hasCheckedConnection &&
        wasConnected;

    private void Start()
    {
        UpdateConnectionVisual(false);

        if (digitalTwinController == null)
        {
            Debug.LogError(
                "ESP32Connection: DigitalTwinController nije povezan u Inspectoru."
            );

            enabled = false;
            return;
        }

        // Coroutine omogucuje cekanje HTTP odgovora bez zaustavljanja Unity scene
        StartCoroutine(PollStatus());
    }

    // Periodicko ocitavanje statusa

    private IEnumerator PollStatus()
    {
        // Petlja traje dok je skripta aktivna, Nakon svakog citanja ceka se
        // refreshInterval, a zatim se ponovno provjerava /status
        while (true)
        {
            if (!commandInProgress)
            {
                yield return ReadStatus();
            }

            yield return new WaitForSeconds(refreshInterval);
        }
    }

    private IEnumerator ReadStatus()
    {
        string statusUrl = baseUrl + "/status";

        // GET zahtjev od ESP32-a trazi samo trenutno stanje sustava
        using (UnityWebRequest request = UnityWebRequest.Get(statusUrl))
        {
            // Nakon dvije sekunde bez odgovora ESP32 se smatra nedostupnim.
            request.timeout = 2;

            yield return request.SendWebRequest();

            if (request.result != UnityWebRequest.Result.Success)
            {
                ReportConnection(false, request.error);
                yield break;
            }

            ReportConnection(true, null);
            ApplyStatusJson(request.downloadHandler.text);
        }
    }

    // Pretvaranje JSON odgovora u stanje Unity modela

    private void ApplyStatusJson(string json)
    {
        ESP32Status status;

        try
        {
            // Primljeni JSON pretvara se u ESP32Status objekt definiran na vrhu.
            status = JsonUtility.FromJson<ESP32Status>(json);
        }
        catch (Exception exception)
        {
            Debug.LogWarning(
                "ESP32 je vratio neispravan JSON: " +
                exception.Message
            );

            return;
        }

        if (status == null)
        {
            Debug.LogWarning(
                "ESP32 status nije moguće pročitati."
            );

            return;
        }

        ApplyStatus(status);
    }

    private void ApplyStatus(ESP32Status status)
    {
        // Nakon uspjesnog citanja ista primljena stanja prikazuju se na 3D modelu
        digitalTwinController.SetDHT11Values(
            status.temperature,
            status.humidity
        );

        digitalTwinController.SetPhotoresistorStatus(
            status.lightPercent,
            status.lightCondition
        );

        digitalTwinController.SetBedroom1Light(
            status.bedroom1
        );

        digitalTwinController.SetWCLight(
            status.wc
        );

        digitalTwinController.SetBedroom2Light(
            status.bedroom2
        );

        digitalTwinController.SetFan(status.fan);
        digitalTwinController.SetDoor(status.doorOpen);
        digitalTwinController.SetBuzzer(status.buzzer);
    }

    // Metode koje pozivaju Unity gumbi

    // Svaki gumb prvo provjerava vezu. Ako postoji veza, naredba ide ESP32-u
    // Bez veze mijenja se samo lokalni Unity model, pa simulacija i dalje radi

    public void ToggleBedroom1FromUnity()
    {
        if (!IsConnected)
        {
            digitalTwinController.ToggleBedroom1FromUI();
            return;
        }

        bool newState =
            !digitalTwinController.devices.bedroom1Light.isOn;

        SendDeviceCommand("bedroom1", newState);
    }

    public void ToggleWCFromUnity()
    {
        if (!IsConnected)
        {
            digitalTwinController.ToggleWCFromUI();
            return;
        }

        bool newState =
            !digitalTwinController.devices.wcLight.isOn;

        SendDeviceCommand("wc", newState);
    }

    public void ToggleBedroom2FromUnity()
    {
        if (!IsConnected)
        {
            digitalTwinController.ToggleBedroom2FromUI();
            return;
        }

        bool newState =
            !digitalTwinController.devices.bedroom2Light.isOn;

        SendDeviceCommand("bedroom2", newState);
    }

    public void ToggleFanFromUnity()
    {
        if (!IsConnected)
        {
            digitalTwinController.ToggleFanFromUI();
            return;
        }

        bool newState =
            !digitalTwinController.devices.fan.isOn;

        SendDeviceCommand("fan", newState);
    }

    public void ToggleDoorFromUnity()
    {
        if (!IsConnected)
        {
            digitalTwinController.ToggleDoorFromUI();
            return;
        }

        bool newState =
            !digitalTwinController.devices.door.isOpen;

        SendDeviceCommand("door", newState);
    }

    public void ToggleBuzzerFromUnity()
    {
        if (!IsConnected)
        {
            digitalTwinController.ToggleBuzzerFromUI();
            return;
        }

        bool newState =
            !digitalTwinController.devices.buzzer.isOn;

        SendDeviceCommand("buzzer", newState);
    }

    public void PressDoorbellFromUnity()
    {
        if (!IsConnected)
        {
            digitalTwinController.PressDoorbellFromUI();
            return;
        }

        if (commandInProgress)
        {
            return;
        }

        StartCoroutine(
            // Zvono ima zasebnu adresu jer ESP32 sam odreduje trajanje zvuka
            SendCommand(baseUrl + "/doorbell")
        );
    }

    // Slanje naredbi prema ESP32-u

    private void SendDeviceCommand(
        string device,
        bool turnOn
    )
    {
        if (digitalTwinController == null ||
            commandInProgress)
        {
            return;
        }

        string state = turnOn ? "on" : "off";

        // Od naziva uredaja i stanja sastavlja se adresa, primjerice:
        // http://192.168.4.1/control?device=fan&state=on
        string url =
            baseUrl +
            "/control?device=" +
            device +
            "&state=" +
            state;

        StartCoroutine(SendCommand(url));
    }

    private IEnumerator SendCommand(string url)
    {
        commandInProgress = true;

        using (UnityWebRequest request =
               UnityWebRequest.Get(url))
        {
            request.timeout = 2;

            yield return request.SendWebRequest();

            if (request.result !=
                UnityWebRequest.Result.Success)
            {
                ReportConnection(
                    false,
                    request.error
                );
            }
            else
            {
                // ESP32 nakon naredbe vraca novi JSON status. Zato Unity moze
                // odmah prikazati stvarno stanje bez cekanja sljedeceg osvjezavanja
                ReportConnection(true, null);
                ApplyStatusJson(
                    request.downloadHandler.text
                );
            }
        }

        commandInProgress = false;
    }

    // Prikaz je li ESP32 dostupan

    private void ReportConnection(
        bool connected,
        string error
    )
    {
        bool stateChanged =
            !hasCheckedConnection ||
            wasConnected != connected;

        hasCheckedConnection = true;
        wasConnected = connected;

        // Tekst i boja u gornjem kutu mijenjaju se prema rezultatu zahtjeva
        UpdateConnectionVisual(connected);

        if (!stateChanged)
        {
            return;
        }

        if (connected)
        {
            Debug.Log(
                "ESP32 je povezan s Unity digitalnim blizancem."
            );
        }
        else
        {
            Debug.LogWarning(
                "ESP32 nije dostupan: " + error
            );
        }
    }

    private void UpdateConnectionVisual(bool connected)
    {
        if (connectionText == null)
        {
            return;
        }

        if (connected)
        {
            connectionText.text =
                "● ESP32 POVEZAN";

            connectionText.color =
                connectedColor;
        }
        else
        {
            connectionText.text =
                "● ESP32 NIJE POVEZAN";

            connectionText.color =
                disconnectedColor;
        }
    }
}
