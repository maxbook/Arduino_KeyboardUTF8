/*
 * ESP32S3 Basic TinyUSB Keyboard Example
 * 
 * This example demonstrates how to use the KeyboardUTF8 library
 * with ESP32S3 and TinyUSB to emulate a USB HID keyboard.
 * 
 * Requirements:
 * - ESP32S3 board
 * - Arduino IDE with ESP32 board support installed
 * - USB Mode set to "USB-OTG (TinyUSB)" in Tools menu
 * 
 * Usage:
 * 1. Upload this sketch to your ESP32S3
 * 2. Connect the ESP32S3 USB port to your computer
 * 3. Open a text editor
 * 4. Press the BOOT button on your ESP32S3 to type text
 */

#include <KeyboardUTF8.h>
#include <languages/Keyboard_US_7.h>  // US keyboard layout

// Use the built-in BOOT button (usually GPIO0)
const int buttonPin = 0;
int lastButtonState = HIGH;

void setup() {
  // Initialize the keyboard
  Keyboard_US_7.begin();
  
  // Setup the button pin
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Wait for USB to be ready
  delay(1000);
  
  // Type a greeting message
  Keyboard_US_7.println("ESP32S3 TinyUSB Keyboard Ready!");
  Keyboard_US_7.println("Press the BOOT button to type more text.");
}

void loop() {
  // Read the button state
  int buttonState = digitalRead(buttonPin);
  
  // Check if button was pressed (state changed from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50); // Debounce delay
    
    // Type some text
    Keyboard_US_7.println("Button pressed! Hello from ESP32S3!");
    Keyboard_US_7.print("UTF-8 characters: ");
    Keyboard_US_7.println("→ ← ↑ ↓ ♥ ★");
    
    // Wait for button release
    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }
  }
  
  lastButtonState = buttonState;
  delay(10);
}
