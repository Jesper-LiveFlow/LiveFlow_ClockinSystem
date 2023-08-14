// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
// Self created
#include "NoDelayDelay.h"

// CONSTANTS
// Connectivity
bool WiFiConnected = true;
bool loggedIn = true;

// VARIABLES
bool updateNFT = true;
String tagId = "None";

// FUNCTIONS V --------------------------------------------------------------

// Run Once
void setup() {
  Serial.begin(115200);

  // initNFC();
  initTFT();
}

// Run forever
void loop() {
  if(!isWiFiConnected()) {
    WiFiConnected = false;
    connectWiFi();
  }
  else {
    WiFiConnected = true;
  }

  if(updateNFT) {
    updateTFT();
  }
}
