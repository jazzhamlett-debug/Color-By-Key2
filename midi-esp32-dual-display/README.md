# 🎹 ESP32 MIDI Dual Display + WiFi SSID Project

This project connects a MIDI keyboard (AKM320) to an ESP32-S3 and:

- Displays notes on a 1.8" TFT screen
- Shows a custom image on an OLED display
- Broadcasts the current note as a WiFi SSID

## 🧰 Hardware
- ESP32-S3
- MidiPlus AKM320
- 1.8" TFT (ST7735)
- OLED DM OLED096-636 (SSD1306)

## 🔌 Wiring

### TFT (SPI)
| TFT Pin | ESP32 |
|--------|------|
| SCK    | GPIO 12 |
| MOSI   | GPIO 11 |
| RES    | GPIO 10 |
| DC     | GPIO 13 |
| CS     | GPIO 14 |

### OLED (I2C)
| OLED Pin | ESP32 |
|---------|------|
| SDA     | GPIO 8 |
| SCL     | GPIO 9 |

## 🚀 Features
- Real-time MIDI note display
- WiFi SSID changes based on key press
- Custom image display

## 📦 Libraries
- Adafruit GFX
- Adafruit ST7735
- Adafruit SSD1306
- ESP32 USB MIDI

## ▶️ Upload Instructions
1. Open in Arduino IDE
2. Select ESP32S3 Dev Module
3. Upload
