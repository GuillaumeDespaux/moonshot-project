// NTP server to request epoch time
const char* ntpServer = "pool.ntp.org";

// Variable to save current epoch time
unsigned long epochTime; 

// Function that gets current epoch time
unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return(0);
  }
  time(&now);
  return now;
}

void time_setup() {
  configTime(0, 0, ntpServer);
}

void print_time() {
  epochTime = getTime();
  Serial.print("Epoch Time: ");
  Serial.println(epochTime);
}