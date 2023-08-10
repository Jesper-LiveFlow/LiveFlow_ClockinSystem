// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
#include <TFT_eSPI.h>

// CONSTANTS
// Screen details
const int screenWidth = 135;
const int screenHeight = 240;

// OBJECTS
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight);

// FUNCTIONS V --------------------------------------------------------------

// Run once
void setup() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);
  
  tft.setTextDatum(TL_DATUM);
  tft.setTextSize(1);

  tft.setCursor(0, 0);
  tft.setTextColor(TFT_WHITE);
  tft.print("WiFi:");
  tft.setCursor(space(), 0);
  tft.setTextColor(TFT_GREEN);
  tft.print("Connected");

  tft.setCursor(0, newLine());
  tft.setTextColor(TFT_WHITE);
  tft.print("Logged in:");
  tft.setCursor(space(), tft.getCursorY());
  tft.setTextColor(true ? TFT_GREEN : TFT_RED);
  tft.print("Yes");
}

// Run forever
void loop() {
  
}
