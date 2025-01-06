#ifndef STRUCT_H
#define STRUCT_H

typedef struct
{
    String id = "\n";
    unsigned long last_time_checked = 0;
    bool is_present = false;
} card;


typedef struct 
{
    String id = "ESP32 Guillaume's Badger"; 
    long signal_lost = 0;

    bool wifi_connected = false;
    bool nfc_connected = false;
} board;

#endif
