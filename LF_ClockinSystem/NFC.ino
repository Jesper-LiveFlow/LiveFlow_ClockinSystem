// DECLARATIONS V -----------------------------------------------------------
// INCLUDES
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

// OBJECTS
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

void initNFC() {
  nfc.begin();
}

void readNFC() {
  if (nfc.tagPresent())
  {
    NfcTag tag = nfc.read();
    tagId = tag.getUidString();
  }
}