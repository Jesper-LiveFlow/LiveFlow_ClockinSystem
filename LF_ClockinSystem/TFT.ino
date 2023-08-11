// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
// Libraries
#include <TFT_eSPI.h>
// Images (to RGB565)
#include "LiveFlowLogo.h"

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
  tft.setRotation(1);

  tft.fillScreen(TFT_WHITE);
  tft.pushImage(tft.width() / 2 - (240) / 2, tft.height() / 2 - (62) / 2, 240, 62, LIVE_FLOW_LOGO_DEF);
  delay(5000);
}

// Update TFT screen
void updateTFT() {
  tft.fillScreen(TFT_WHITE);
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
  tft.setCursor(1, bottom(2, 1));
  tft.setTextColor(TFT_LIVEFLOW_TEXTGRAY);
  tft.print("WiFi:");
  tft.setCursor(space(), tft.getCursorY());
  tft.setTextColor(WiFiConnected ? TFT_LIVEFLOW_GREEN : TFT_LIVEFLOW_RED);
  tft.print(WiFiConnected ? "Connected" : "Disconnected");

  // Logged in
  tft.setCursor(1, newLine());
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

  int y = newLine();
  tft.setTextSize(1);
  tft.setCursor(middleX(tagId), y);
  tft.print(tagId);
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
int bottom(byte lines, byte spaceFromBottom) {
  return tft.height() - (tft.fontHeight() * lines) - (2 * (lines - 1)) - spaceFromBottom;
}
