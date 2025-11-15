#include <KeyboardUTF8.h>
#include <languages/Keyboard_GR.h>

// German keyboard layout for ESP32S3 with TinyUSB

void setup()
{
  Keyboard_GR.begin();
  delay(1000); // Wait for USB to initialize
  Keyboard_GR.println("This is a test: ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  Keyboard_GR.println("Umlauts: äöüÄÖÜß");
}

void loop() {}
