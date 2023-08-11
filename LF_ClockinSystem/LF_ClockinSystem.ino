// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
// ...

// CONSTANTS
// Connectivity
bool WiFiConnected = true;
bool loggedIn = true;

// VARIABLES
String tagId = "None";

// FUNCTIONS V --------------------------------------------------------------

// Run Once
void setup() {
  Serial.begin(115200);

  initNFC();
  initTFT();
}

// Run forever
void loop() {
  updateTFT();
  readNFC();
}
