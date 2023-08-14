// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
#include <WiFi.h>

// CONSTANTS
// WiFi network credentials
const String WF_SSID = "Weijnen";
const String WF_PASSWORD = "Paul19683!";

// OBJECTS
NoDelayDelay connectWiFiDelay(2000);

// FUNCTIONS V --------------------------------------------------------------

bool isWiFiConnected() {
  return WiFi.status() == WL_CONNECTED;
}

void connectWiFi() {
  if(connectWiFiDelay.check()) {
    // WiFi.begin(WF_SSID, WF_PASSWORD);
    Serial.println("Test");
  }
}