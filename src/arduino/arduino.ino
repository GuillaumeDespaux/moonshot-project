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

// YAML
#include <ArduinoJson.h>
#include <YAMLDuino.h>

// TIME + INTERN CONNECTION
#include "infrastructure.h"
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
const int batteryPin = 34; // GPIO34 on the ESP32
const float referenceVoltage = 3.3; // Reference voltage for the ESP32
const float minVoltage = 3.0; // Minimum voltage for the battery
const float maxVoltage = 4.2; // Maximum voltage for the battery


/*
###################
# INITIALIZATION  #
###################
*/

// Initialize the NFC shield with I2C connection
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

board Board;

// Add the card to the array
static card array[MAX_CARDS];  // Define the array to store cards
static uint8_t card_count = 0;  // Keep track of the number of cards

// WiFi
infrastructure Infrastructure;
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
  pinMode(batteryPin, INPUT);

  
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
  Board.wifi_connected = check_last_internet_connection();
  digitalWrite(green_led, HIGH);
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


  if (card_count == 10) {
    for (uint8_t i = 0; i < card_count; i++) {
      send_cards_data_to_database(array);
  }
    Serial.println("Data sent to database");
    request_internet_connection();
    delete_all_cards(array);
  }
  print_time();

  int analogValue = analogRead(batteryPin); // Read the analog value from the battery pin
  float voltage = (analogValue * referenceVoltage) / 4095.0; // Convert to voltage

  // Calculate the battery percentage
  float batteryPercentage = ((voltage - minVoltage) / (maxVoltage - minVoltage)) * 100.0;

  // Ensure the battery percentage is within the range of 0 to 100
  if (batteryPercentage > 100.0) {
    batteryPercentage = 100.0;
  } else if (batteryPercentage < 0.0) {
    batteryPercentage = 0.0;
  }

  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" | Battery Voltage: ");
  Serial.print(voltage);
  Serial.print(" V | Battery Percentage: ");
  Serial.print(batteryPercentage);
  Serial.println(" %");
  
  print_YAML();
}