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

    // Add the card to the array
    static card array[MAX_CARDS];  // Define the array to store cards
    static uint8_t card_count = 0;  // Keep track of the number of cards
    
    
    if (card_count < MAX_CARDS) {
      
      Serial.println(String(array[card_count-1].id) + " =? " + String(card_ui.id));
      if (array[card_count-1].id != "\0" || array[card_count+1].id != "\0" || array[card_count].id != card_ui.id) {
        request_processing_start();
        for (uint8_t i = 0; i < MAX_CARDS; i++) {
          Serial.println("Card number : " + String(i + 1));
          if (array[i].id == card_ui.id) {
            card_ui.is_present = true;
            Serial.println("Card already registered");
            request_processing_end();
            request_failed();
            break;
          }
        }
        request_processing_end();

      }
      
      
      if (!card_ui.is_present) {
        card_ui.last_time_checked = getTime();
        card_ui.is_present = true;
        array[card_count] = card_ui;
        card_count++;
        Serial.println("Card added to the array");
        request_success();
      }
    }
      
    else if (card_count == MAX_CARDS) {
      for (uint8_t i = 0; i < MAX_CARDS; i++) {
        array[i].id = "\0";
        array[i].last_time_checked = 0;
        array[i].is_present = false;
        Serial.println("Card " + String(i + 1) + " removed");
      }
      card_count = 0;
    } 
    else {
      Serial.println("Card array is full!");
    }

    // Print all cards in the array
    Serial.println("Cards in array:");
    for (uint8_t i = 0; i < card_count; i++) {
      Serial.print("Card ");
      Serial.print(i + 1);
      Serial.print(": ID = ");
      Serial.print(array[i].id);
      Serial.print(", Last Time Checked = ");
      Serial.println(array[i].last_time_checked);
    }
    
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

// void registerCard(String ui_transform, card deck_of_cards[MAX_CARDS]) {
//   bool cardRegistered = false;

//   // Check if the card is already registered
//   for (uint16_t i = 0; i < MAX_CARDS; i++) {
//     if (deck_of_cards[i].id == ui_transform) {
//       Serial.println("Card already registered");
//       cardRegistered = true;
//       break;
//     }
//   }

//   // Register the card if it's not already registered
//   if (!cardRegistered) {
//     for (uint16_t i = 0; i < MAX_CARDS; i++) {
//       if (deck_of_cards[i].id == "") {  // Find the first empty slot
//         deck_of_cards[i].id = ui_transform;
//         // Cards[i].last_time_checked = getTime();
//         Serial.println("Card registered");
//         break;
//       }
//     }
//   }

//   // Print the content of the Cards array
//   Serial.println("Cards array content:");
//   for (uint16_t i = 0; i < 10; i++) {
//     Serial.print(i + ":");
//     if (deck_of_cards[i].id != "") {
//       Serial.println(deck_of_cards[i].id);
//     }
//   }
// }