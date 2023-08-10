// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
// ...

// CONSTANTS
// Connectivity
bool WiFiConnected = true;
bool loggedIn = true;

// FUNCTIONS V --------------------------------------------------------------

// Run Once
void setup() {
  initTFT();
}

// Run forever
void loop() {
  updateTFT();
}
