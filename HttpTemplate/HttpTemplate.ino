// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>

// DEFINES
// Returns length of array (usage: ARRAYLENGTH(array))
#define ARRAYLENGTH(x) (sizeof(x)/sizeof(x[0]))

// VARIABLES
String JWTToken = "";

// FUNCTIONS V --------------------------------------------------------------

// Run once
void setup() {
  // Start Serial Monitor
  Serial.begin(115200);
}

// Run forever
void loop() {
  // If WiFi is connected
  if(WiFi.status() == WL_CONNECTED) {
    if(JWTToken != "") {
      
    }
    else {
      setJWTToken();
    }
  }
  // Else connect with WiFi
  else {
    connectWiFi();
  }
}
