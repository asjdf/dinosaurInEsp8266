#include "heltec.h"  // alias for `#include "SSD1306Wire.h"`
#include "images.h"
#define FPS 25
String serialTemp = "";
int y = 23;
int speed = 1000;  // ms
int bgPos = 0;     // 背景偏移
long long bgFlashTime;
long long flashTime;
int screenFlashTime = 1000 / FPS;

void display() {
    Heltec.display->clear();
    // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
    // on how to create xbm files
    Heltec.display->drawXbm(bgPos, 23, bg_width, bg_height, bg_bits);
    Heltec.display->drawXbm(255 + bgPos, 23, bg_width, bg_height, bg_bits);
    Heltec.display->drawXbm(0, 11, dinosaur0_width, dinosaur0_height,
                            dinosaur0_bits);
    Heltec.display->display();
}

void setup() {
    Heltec.begin(true /*DisplayEnable Enable*/, true /*Serial Enable*/);

    Heltec.display->flipScreenVertically();
    Heltec.display->setFont(ArialMT_Plain_10);
    flashTime = millis();
}

void loop() {
    if (millis() - bgFlashTime >= speed) {
        bgFlashTime = millis();
        bgPos = (bgPos - 1) % bg_width;
        Serial.println(bgPos);
    }
    while (Serial.available() > 0) {
        int inChar = Serial.read();
        if (isDigit(inChar)) {
            serialTemp += (char)inChar;
        }
        if (inChar == '\n') {
            speed = serialTemp.toInt();
            serialTemp = "";
        }
    }
    if (millis() - flashTime >= screenFlashTime) {
        display();
    }
}