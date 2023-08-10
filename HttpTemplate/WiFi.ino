// DECLARATIONS V -----------------------------------------------------------
// CONSTANTS
// WiFi network credentials
const String WF_SSID = "J-Samsung";
const String WF_PASSWORD = "Jesper123";

// FUNCTIONS V --------------------------------------------------------------

// Connect to WiFi function
void connectWiFi() {
  // Start connecting to WiFi
  WiFi.begin(WF_SSID, WF_PASSWORD);
  Serial.print("Connecting");
  // Wait untill the WiFi is connected
  byte timesChecked = 0;
  while(WiFi.status() != WL_CONNECTED) {
    timesChecked++;
    Serial.print(".");

    if(timesChecked > 20) {
      Serial.println("\nFailed to connect to WiFi");
      WiFi.disconnect();
      break;
    }
    delay(500);
  }

  if(WiFi.status() == WL_CONNECTED) {
    Serial.print("\nConnected to WiFi network with IP Adress: ");
    Serial.println(WiFi.localIP());
  }
}
