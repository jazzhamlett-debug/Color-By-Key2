#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ST7735.h>

#include "USB.h"
#include "USBMidi.h"

// -------- OLED --------
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

// -------- TFT --------
#define TFT_CS   14
#define TFT_DC   13
#define TFT_RST  10
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// -------- MIDI --------
USBMidi midi;

// -------- WiFi --------
String currentSSID = "Waiting...";

String getNoteName(int note) {
  String names[] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
  int octave = (note / 12) - 1;
  return names[note % 12] + String(octave);
}

void updateSSID(String name) {
  WiFi.softAPdisconnect(true);
  delay(100);
  WiFi.softAP(name.c_str());
  Serial.println("SSID: " + name);
}

void setup() {
  Serial.begin(115200);

  Wire.begin(8, 9);
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(20, 25);
  oled.println("LOGO");
  oled.display();

  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(3);

  USB.begin();
  midi.begin();

  updateSSID(currentSSID);
}

void loop() {
  midi.read();

  if (midi.available()) {
    midi_event_t event = midi.read();
    int status = event.status & 0xF0;

    if (status == 0x90 && event.data2 > 0) {
      String note = getNoteName(event.data1);

      tft.fillScreen(ST77XX_BLACK);
      tft.setCursor(20, 50);
      tft.println(note);

      updateSSID(note);

      Serial.println(note);
    }
  }
}
