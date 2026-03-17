#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include <music_player.h>
#include <songs.h>

const int g_iBtnPINs[] = {14, 13, 12, 15}; // UP, DOWN, LEFT, RIGHT
const int g_iMusicPin = 18;
const int g_iMusicButtonPin = 23;

// ESP NOW
const uint8_t g_iRecieverAdress[] = {0x94, 0xE6, 0x86, 0xA8, 0x61, 0x24};
esp_now_peer_info_t g_peerInfo; // information about the peer

int g_iBtnPinValues[4] = {0, 0, 0, 0}; // values in btnPINs
// this variable's value is sent to the reciever
// the values instruct the robotCar on its next action

typedef struct struct_message {
    int m_iCommand; // this variable's value is sent to the reciever
} struct_message;

struct_message g_messageToSend;
// ESP NOW

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  //Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

unsigned long g_flLastSentTime = 0;

CMusicPlayer g_musicPlayer;

bool g_bMusicButtonPressed = false;

volatile bool g_bButtonPressed = false;
unsigned long g_flLastInterruptTime = 0;

void IRAM_ATTR MusicButtonInterrupt()
{
  if( millis() - g_flLastInterruptTime > 200 ) {
    g_bMusicButtonPressed = true;
    g_flLastInterruptTime = millis();
  }
}


int g_iCurrentSong = 0;
#define g_iSongCount 4

const int *g_szSongs[g_iSongCount] =
{
  tetris,
  keyboardcat,
  vader,
  takeonme
};

size_t g_iSongSize[g_iSongCount] = 
{
  sizeof(tetris),
  sizeof(keyboardcat),
  sizeof(vader),
  sizeof(takeonme)
};

const int g_iSongTempos[g_iSongCount] = 
{
  144,
  160,
  120,
  140
};


void setup() {
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  
  // initialise ESP NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register peer
  memcpy(g_peerInfo.peer_addr, g_iRecieverAdress, 6);
  g_peerInfo.channel = 0;
  g_peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&g_peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);

  for(int i=0; i<4; i++){
     pinMode(g_iBtnPINs[i], INPUT_PULLUP); 
  }
  
  pinMode( g_iMusicPin, OUTPUT );
  pinMode( g_iMusicButtonPin, INPUT_PULLUP );

  attachInterrupt(g_iMusicButtonPin, MusicButtonInterrupt, RISING);

  g_musicPlayer.Init(g_iMusicPin);
}

void loop() {

  if(!digitalRead(g_iBtnPINs[3])){ // if RIGHT
    g_messageToSend.m_iCommand = 4;
  } else if(!digitalRead(g_iBtnPINs[2])){ // if LEFT
    g_messageToSend.m_iCommand = 3;
  }else if(!digitalRead(g_iBtnPINs[1])){ // if DOWN
    g_messageToSend.m_iCommand = 2;
  }else if(!digitalRead(g_iBtnPINs[0])){ // if UP
    g_messageToSend.m_iCommand = 1;
  }else{
    g_messageToSend.m_iCommand = 0;
  }

  //Serial.println(messageToSend.command);

  //ESP NOW send the message and get the result
  if( millis() - g_flLastSentTime > 50 ){
    //Serial.println("sending " + g_messageToSend.m_iCommand);
    g_flLastSentTime = millis();

    esp_err_t result = esp_now_send(g_iRecieverAdress, (uint8_t *) &g_messageToSend, sizeof(g_messageToSend));
  }
  

  g_musicPlayer.Think();

  if( g_bMusicButtonPressed ) {
      g_musicPlayer.StartPlayback(g_szSongs[g_iCurrentSong], g_iSongSize[g_iCurrentSong], g_iSongTempos[g_iCurrentSong]);

      g_iCurrentSong++;

      if( g_iCurrentSong >= g_iSongCount )
        g_iCurrentSong = 0;

      g_bMusicButtonPressed = false;
  }
}
