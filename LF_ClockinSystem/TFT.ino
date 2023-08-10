// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
#include <TFT_eSPI.h>

// CONSTANTS
// Screen details
const int screenWidth = 135;
const int screenHeight = 240;

// DEFINES
#define TFT_LIVEFLOW_LIGHTBLUE 0x2212
#define TFT_LIVEFLOW_BLUE 0x192b
#define TFT_LIVEFLOW_RED 0xea28
#define TFT_LIVEFLOW_GREEN 0x262b
#define TFT_LIVEFLOW_TEXTGRAY 0x3a0a

// OBJECTS
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight);

// FUNCTIONS V --------------------------------------------------------------
// MAIN FUNCTIONS
// Initialize TFT screen
void initTFT() {
  tft.init();
  tft.fillScreen(TFT_WHITE);
  tft.setRotation(1);
}

// Update TFT screen
void updateTFT() {
  updateTFTConnectivity();
  updateTFTTag();
}

// SUB FUNCTIONS
// Update connectivity part of TFT screen
void updateTFTConnectivity() {
  // Text settings
  tft.setTextDatum(TL_DATUM);
  tft.setTextSize(1);

  // WiFi connected
  tft.setCursor(0, bottom(2));
  tft.setTextColor(TFT_LIVEFLOW_TEXTGRAY);
  tft.print("WiFi:");
  tft.setCursor(space(), tft.getCursorY());
  tft.setTextColor(WiFiConnected ? TFT_LIVEFLOW_GREEN : TFT_LIVEFLOW_RED);
  tft.print(WiFiConnected ? "Connected" : "Disconnected");

  // Logged in
  tft.setCursor(0, newLine());
  tft.setTextColor(TFT_LIVEFLOW_TEXTGRAY);
  tft.print("Logged in:");
  tft.setCursor(space(), tft.getCursorY());
  tft.setTextColor(loggedIn ? TFT_LIVEFLOW_GREEN : TFT_LIVEFLOW_RED);
  tft.print(loggedIn ? "Yes" : "No");
}

// Update tag part of TFT screen
void updateTFTTag() {
  // Text settings
  tft.setTextDatum(MC_DATUM);
  tft.setTextSize(2);
  tft.setTextColor(TFT_LIVEFLOW_TEXTGRAY);

  tft.setCursor(middleX("Waiting for tag..."), middleY());
  tft.print("Waiting for tag...");
}

// HELP FUNCTIONS
// Center text in X axis
int middleX(String text) {
  return tft.width() / 2 - tft.textWidth(text) / 2;
}

// Center text in Y axis
int middleY() {
  return tft.height() / 2 - tft.fontHeight() / 2;
}

// Insert a space (X)
int space() {
  return tft.getCursorX() + 2;
}

// Insert a new line (Y)
int newLine() {
  return tft.getCursorY() + tft.fontHeight() + 2;
}

// Return Y value from where to write from when you want your lowest textline to be connected to the bottom of the screen
int bottom(byte lines) {
  return tft.height() - (tft.fontHeight() * lines) - (2 * (lines - 1));
}
