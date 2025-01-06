/*
  Permit to read NFC card and register it in the system
*/
void nfc_read(void) {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

  // Wait for an NTAG203 card.  When one is found 'uid' will be populated with
  // the UID, and uidLength will indicate the size of the UUID (normally 7)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 5000); // 5000 stand for ms while active and continue
 

  if (success) {
    // Display some basic information about the card
    nfc.PrintHex(uid, uidLength);
    String card_id = card_transpose(uid, uidLength);
    
    card card_ui;
    card_ui.id = card_id;

    Serial.println(card_ui.id);

    if (card_count < MAX_CARDS) {
      Serial.println(card_count < MAX_CARDS);
      if (card_count > 0) {
        Serial.println(card_count > 0);
        if (array[card_count-1].id == card_ui.id){
          card_ui.is_present = true;        
          request_failed();
        } 
        else {
          request_processing_start();
          for (uint8_t i = 0; i < MAX_CARDS; i++) {
            Serial.println("Card number : " + String(i+1));
            if (array[i].id == card_ui.id ) {
              card_ui.is_present = true;
              Serial.println("Card already registered");
              request_processing_end();
              request_failed();
              break;
            }
          }
          request_processing_end();
        }
      }
    }

    Serial.println("card_count = " + String(card_count));
    if (!card_ui.is_present) {
      card_ui.last_time_checked = getTime();
      card_ui.is_present = true;
      array[card_count] = card_ui;
      card_count++;
      Serial.println("Card added to the array");
      request_success();
    }
      
    else if (card_count == MAX_CARDS) {
      delete_all_cards(array);
    }
    
    print_all_cards(array);
    
    Serial.println("Current index = " + String(card_count));
    
    if (uidLength == 7)
    {
      uint8_t data[32];

      // We probably have an NTAG2xx card (though it could be Ultralight as well)
      Serial.println("Seems to be an NTAG2xx tag (7 byte UID)");


      for (uint8_t i = 0; i < 42; i++)
      {
        success = nfc.ntag2xx_ReadPage(i, data);

        // Display the current page number
        Serial.print("PAGE ");
        if (i < 10)
        {
          Serial.print("0");
          Serial.print(i);
        }
        else
        {
          Serial.print(i);
        }
        Serial.print(": ");

        // Display the results, depending on 'success'
        if (success)
        {
          // Dump the page data
          nfc.PrintHexChar(data, 4);
        }
        else
        {
          Serial.println("Unable to read the requested page!");
        }
      }
    }
    else
    {
      Serial.println("This doesn't seem to be an NTAG203 tag (UUID length != 7 bytes)!");
    }

    // Wait a bit before trying again
    Serial.println("\n\nSend a character to scan another tag!");
    Serial.flush();
    // while (!Serial.available());
    while (Serial.available()) {
    Serial.read();
    }
    Serial.flush();
  }
  else {
    Serial.println("No card detected.");
  }
}

String card_transpose(uint8_t uid[], uint8_t uidLength) {
  // Transform the CARD ID HEX in String removing : "0x", " "
  String ui_transform;
  for (uint8_t i = 0; i < uidLength; i++) {
    ui_transform += String(uid[i], HEX);
  }
  ui_transform.toUpperCase();
  return ui_transform;
}

void print_all_cards(card array[MAX_CARDS]){
      // Print all cards in the array
    Serial.println("Cards in array:");
    for (uint8_t i = 0; i < card_count; i++) {
      Serial.print("Card ");
      Serial.print(i);
      Serial.print(": ID = ");
      Serial.print(array[i].id);
      Serial.print(", Last Time Checked = ");
      Serial.println(array[i].last_time_checked);
    }
}

void delete_all_cards(card array[MAX_CARDS]){
  Serial.println("Card array is full!");
  for (uint8_t i = 0; i < MAX_CARDS; i++) {
    array[i].id = "\0";
    array[i].last_time_checked = 0;
    array[i].is_present = false;
    Serial.println("Card " + String(i + 1) + " removed");
  }
  card_count = 0;
}