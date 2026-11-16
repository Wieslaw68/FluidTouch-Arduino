# FluidTouch — Arduino IDE package

This folder is a conversion of the supplied PlatformIO project into an Arduino IDE sketch layout.
The firmware source is retained under `src/` and headers under `include/`. `setup()` and `loop()`
remain in `src/main.cpp`; the `.ino` file is only the Arduino sketch entry point.

## Target preset

The default target is **Waveshare ESP32-S3-Touch-LCD-7 (SKU 27078)**:

- ESP32-S3, 16 MB Flash, 8 MB Octal PSRAM
- 800 × 480 RGB display
- GT911 capacitive touch (I²C: SDA GPIO8, SCL GPIO9)
- CH422G I/O expander for display backlight and touch reset
- Build defines: `HARDWARE_WAVESHARE` and `BACKLIGHT_CH422G`

The matching 16 MB partition table is `partitions.csv` (also named `default_16MB.csv`).
The original project includes a separate Elecrow configuration, but it is not enabled by default.

## Arduino IDE setup

1. Install **esp32 by Espressif Systems** in Boards Manager. Use an ESP32 Arduino core compatible
   with the project's ESP-IDF 5.x / Arduino-ESP32 APIs (the original PlatformIO project pins a
   pioarduino ESP32 platform release; the Arduino IDE core version is not automatically pinned).
2. Open `FluidTouch-Arduino.ino`.
3. Select **ESP32S3 Dev Module** (or the exact compatible ESP32-S3 board) for Waveshare ESP32-S3-Touch-LCD-7.
4. Set Flash Size to 16MB, PSRAM to OPI PSRAM, USB CDC On Boot disabled, CPU Frequency 240MHz, Flash Mode QIO, and the partition scheme matching `partitions.csv`.
   Select a partition layout matching the included `partitions.csv`.
5. Install these libraries through Library Manager:
   - LVGL **9.5.0**
   - LovyanGFX **1.2.29**
   - ArduinoWebsockets **0.5.4**
   - ArduinoJson **7.4.3**
6. Build and upload.

## Important limitations

This is a project-layout and build-configuration conversion, not a verified successful Arduino IDE
build. PlatformIO's `custom_sdkconfig = CONFIG_SPIRAM_XIP_FROM_PSRAM=y` has no direct equivalent
in a normal Arduino sketch build; the Arduino IDE package therefore cannot guarantee identical
PSRAM/XIP behavior or display performance. The PlatformIO project also uses a specific pioarduino
platform release, so library/core compatibility must be checked in the Arduino IDE.

The archive included a project-specific `include/lv_conf.h`; it is retained and the include path is
added in `build_opt.h`. The ADS1115 joystick implementation is retained unchanged in
`src/ui/tabs/control/ui_tab_control_joystick.cpp`.


### Korekta obrazu RGB (Waveshare)

W konfiguracji magistrali RGB ustawiono `pclk_idle_high = 1`, zgodnie z referencyjną konfiguracją LovyanGFX dla Waveshare ESP32-S3-Touch-LCD-7. Zmiana może usunąć artefakty/niestabilność próbkowania obrazu. Nie jest to jednak potwierdzenie testem na fizycznym panelu.
