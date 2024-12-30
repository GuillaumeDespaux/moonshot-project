/*
############
# INCLUDES #
############
*/

// NFC
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>

// WIFI
#include <NetworkClient.h>
#include <WiFiAP.h>
#include <WiFi.h>

// TIME + INTERN CONNECTION
#include "internet_connection.h"
#include "struct.h"
#include "time.h"

/*
############
# DEFINES  #
############
*/

#ifndef LED_BUILTIN
#define LED_BUILTIN 2  // Set the GPIO pin where you connected your test LED or comment this line out if your dev board has a built-in LED
#endif

// Define the pins for I2C communication
#define PN532_IRQ   (2)
#define PN532_RESET (3)  // Not connected by default on the NFC Shield

#define MAX_CARDS 100

/*
########
# PIN  #
########
*/

int buzzer = 25;
int red_led = 26;
int green_led = 27;
int yellow_led = 14;
int blue_led = 12;

/*
###################
# INITIALIZATION  #
###################
*/

// Initialize the NFC shield with I2C connection
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

boardGuill Board;


// WiFi
internet_connection Internet;
NetworkServer server(80);

/*
###################
# FUNCTIONS       #
###################
*/

void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10); // for Leonardo/Micro/Zero

  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(2, OUTPUT);  // set the LED pin mode

  
  Serial.println("Boot of the device :" + Board.id);

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }

  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. "); Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.'); Serial.println((versiondata >> 8) & 0xFF, DEC);

  Serial.println("Waiting for an ISO14443A Card ...");

  wifi_setup();
  time_setup();
}

void loop() {
  wifi();
  Board.wifi_connected = CheckLastConne();

  if (!Board.wifi_connected && Board.signal_lost == 0) {
    Board.signal_lost = millis();
  } else if (Board.wifi_connected) {
    Board.signal_lost = 0;
  }

  nfc_read();

  Serial.print("BOARD ID : ");
  Serial.println(Board.id);
  Serial.print("Connection out since : ");
  Serial.println(Board.signal_lost);
  Serial.println("");


  print_time();
}