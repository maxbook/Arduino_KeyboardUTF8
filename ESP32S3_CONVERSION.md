# ESP32S3 TinyUSB Conversion Summary

## Overview
This library has been converted from Arduino Leonardo/Micro/Due to ESP32S3 with TinyUSB support.

## Key Changes

### 1. Header File (KeyboardUTF8.h)
- **Removed**: `#include <Keyboard.h>`
- **Added**: `#include "USB.h"` and `#include "USBHID.h"`
- **Changed**: Added explicit KEY_* definitions for TinyUSB
- **Changed**: Added `USBHIDKeyboard keyboard` member variable

### 2. Implementation File (KeyboardUTF8.cpp)
- **Added**: `begin()` method that initializes USB and keyboard
- **Removed**: All `pgm_read_word()` calls (ESP32 doesn't need PROGMEM)
- **Changed**: All `Keyboard.*` calls to `keyboard.*` (instance instead of static)

### 3. Language Files (206 files in src/languages/)
- **Removed**: `PROGMEM` keyword from all array declarations
- **Reason**: ESP32 automatically stores const data in flash memory

### 4. Library Configuration (library.properties)
- **Changed**: `architectures=*` → `architectures=esp32`
- **Updated**: Description to mention ESP32S3 and TinyUSB

### 5. Documentation (README.md)
- **Added**: Comprehensive setup instructions
- **Added**: TinyUSB configuration steps
- **Added**: Troubleshooting section
- **Updated**: Usage examples for ESP32S3

### 6. Examples
- **Updated**: Keyboard_GR example for ESP32S3
- **Added**: ESP32S3_Basic example with button interaction

## Technical Details

### PROGMEM Removal
On AVR-based Arduinos (Leonardo/Micro), `PROGMEM` is needed to store data in flash instead of RAM. 
ESP32 automatically places const data in flash, making `PROGMEM` unnecessary and incompatible.

### TinyUSB API
- **Old**: Global `Keyboard` object from Arduino core
- **New**: `USBHIDKeyboard` instance from ESP32 TinyUSB
- **Methods remain similar**: `begin()`, `press()`, `release()`, `write()`

### USB Initialization
ESP32S3 requires explicit USB initialization:
```cpp
USB.begin();        // Initialize USB subsystem
keyboard.begin();   // Initialize HID keyboard
```

## Compilation Requirements

### Arduino IDE Settings
1. Board: ESP32S3 Dev Module (or similar ESP32S3 board)
2. **USB Mode: USB-OTG (TinyUSB)** ← CRITICAL SETTING
3. Upload Mode: UART0 / Hardware CDC

### ESP-IDF Compilation
For direct ESP-IDF usage, ensure:
- TinyUSB component is enabled
- USB HID class is included
- Board has USB OTG capability (ESP32S3)

## Compatibility

### Supported
✅ ESP32S3 boards with native USB
✅ Arduino IDE with ESP32 board support
✅ PlatformIO with ESP32 platform
✅ ESP-IDF framework

### Not Supported
❌ ESP32 (original - no native USB)
❌ ESP32-C3 (different USB implementation)
❌ ESP32-S2 (may work but untested)
❌ Arduino Leonardo/Micro/Due (original target)

## Testing Checklist

To verify the conversion works:
1. ✅ Code compiles without errors for ESP32S3
2. ✅ No PROGMEM references remain
3. ✅ USB.h and USBHID.h headers are included
4. ✅ keyboard instance (not static Keyboard) is used
5. ✅ begin() method initializes USB
6. ✅ Examples are updated for ESP32S3

## Migration Path for Users

If you were using the old Arduino Leonardo/Micro version:

1. **Install ESP32 board support** in Arduino IDE
2. **Select ESP32S3 board** (not Leonardo)
3. **Set USB Mode to TinyUSB** in Tools menu
4. **Update code**: No changes needed if using language headers
5. **Upload**: May need to manually enter bootloader mode

## Future Improvements

Potential enhancements (not in current scope):
- Add dual-mode support (both Arduino and ESP32)
- Add ESP32-S2 support
- Add BLE keyboard support
- Add custom HID descriptor support
