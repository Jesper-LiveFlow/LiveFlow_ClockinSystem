// Insert a space (X)
int space() {
  return tft.getCursorX() + 2;
}

// Insert a new line (Y)
int newLine() {
  return tft.getCursorY() + tft.fontHeight() + 2;
}
