//#define SHOW_DEBUG_MESSAGES

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

#include "motor_control.h"
#include "ultrasonic_control.h"

#include "music_player.h"
#include "songs.h"
#include "blinker.h"

const int blinkerLeftPIN = 13;
const int blinkerRightPIN = 12;
const int buzzerPIN = 18;

const int ultrasonicBackRecievePIN = 5;
const int ultrasonicBackSendPIN = 15;
const int ultrasonicFrontRecievePIN = 4;
const int ultrasonicFrontSendPIN = 14;

// defining motor control pins
unsigned int motorInputPIN1 = 21;
unsigned int motorInputPIN2 = 22;
unsigned int motorInputPIN3 = 23;
unsigned int motorInputPIN4 = 19;

// -- ESP NOW --
uint8_t g_iSenderAddress[] = {0x7C, 0x87, 0xCE, 0xF8, 0xCA, 0xE8};

int g_iCommand = 0; // values of recieved message
// UP, DOWN, LEFT, RIGHT

typedef struct struct_message { // structure of receiving message
    int m_iCommand;
} struct_message;

struct_message g_incomingCode;

esp_now_peer_info_t g_peerInfo;

// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
// -- ESP NOW --

CUltrasonicControl g_ultrasonicControlBack(ultrasonicBackRecievePIN, ultrasonicBackSendPIN);
CUltrasonicControl g_ultrasonicControlForward(ultrasonicFrontRecievePIN, ultrasonicFrontSendPIN);

CBlinker g_rightBlinker;
CBlinker g_leftBlinker;
CMusicPlayer g_backwardsBuzzer;

CMotorControl g_motorControl(motorInputPIN1,motorInputPIN2,motorInputPIN3,motorInputPIN4);

void setup() {
  Serial.begin(115200);
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

   // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register peer
  memcpy(g_peerInfo.peer_addr, g_iSenderAddress, 6);
  g_peerInfo.channel = 0;  
  g_peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&g_peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(OnDataRecv);

  g_motorControl.MotorSetup();

  g_rightBlinker.Init(blinkerRightPIN);
  g_leftBlinker.Init(blinkerLeftPIN);
  g_backwardsBuzzer.Init(buzzerPIN);
}

enum MOVE_DIRECTION
{
  STOP = 0,
  FORWARDS,
  BACKWARDS,
  RIGHT,
  LEFT,
};

void loop() {
  g_ultrasonicControlForward.Think();
  g_ultrasonicControlBack.Think();
  g_rightBlinker.Think();
  g_leftBlinker.Think();
  g_backwardsBuzzer.Think();

  switch( g_iCommand ) {
    case STOP:
      g_motorControl.Stop();
      break;

    case FORWARDS:
      if( g_ultrasonicControlForward.GetCM() < 10 ) {
        g_motorControl.Stop();
        break;
      }
      g_motorControl.DriveForward();
      break;

    case BACKWARDS:
      if( g_ultrasonicControlBack.GetCM() < 10 ) {
        g_motorControl.Stop();
        break;
      }

      if( !g_backwardsBuzzer.IsPlaying() )
        g_backwardsBuzzer.StartPlayback(parking, sizeof(parking), 66);

      g_motorControl.DriveBackward();
      break;

    case RIGHT:
      if( !g_rightBlinker.IsBlinking() )
        g_rightBlinker.StartPlayback(led_blink_back, sizeof(led_blink_back), 1, true);

      g_motorControl.TurnRight();
      break;

    case LEFT:
      if( !g_leftBlinker.IsBlinking() )
        g_leftBlinker.StartPlayback(led_blink_back, sizeof(led_blink_back), 1, true);

      g_motorControl.TurnLeft();
      break;
  }

  if( g_iCommand != LEFT && g_iCommand != RIGHT ) {
    g_leftBlinker.Stop();
    g_rightBlinker.Stop();
  }

  if( g_backwardsBuzzer.IsPlaying() && g_iCommand != BACKWARDS )
    g_backwardsBuzzer.Stop();
}

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&g_incomingCode, incomingData, sizeof(g_incomingCode)); // incomingData is the data that has been sent from the transmitter
  // incomingCode is the structure that matches the data structure of the transmitted message

  g_iCommand = g_incomingCode.m_iCommand; // alter te value of variables
}


