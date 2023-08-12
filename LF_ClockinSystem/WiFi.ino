// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
#include <WiFi.h>

// CONSTANTS
// WiFi network credentials
const String WF_SSID = "Weijnen";
const String WF_PASSWORD = "Paul19683!";

unsigned long myTime = millis();

// FUNCTIONS V --------------------------------------------------------------

bool isWiFiConnected() {
  return WiFi.status() == WL_CONNECTED;
}

void connectWiFi() {
  if(millis() - myTime >= 1500) {
    myTime = millis();
    // WiFi.begin(WF_SSID, WF_PASSWORD);
    Serial.println("Test");
  }
}