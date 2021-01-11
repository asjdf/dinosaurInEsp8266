#include "heltec.h"  // alias for `#include "SSD1306Wire.h"`
#include "images.h"
#define FPS 25
#define BGSPEED 100  //背景每秒走的格子数
String serialTemp = "";

int bgPos = 0;  // 背景偏移
long long lastDinosaurFlashTime;
long long lastBgFlashTime;
long long lastScreenFlashTime;
int screenFlashTime = 1000 / FPS;   // 屏幕的刷新时间间隔
int bgFlashSpeed = 1000 / BGSPEED;  // 背景的刷新时间间隔ms
int dinosaurFlashTime = 100;        // 小恐龙的刷新时间间隔 单位ms
int dinosaurState = 0;

void display() {
    Heltec.display->clear();
    // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
    // on how to create xbm files
    Heltec.display->drawXbm(bgPos, 23, bg_width, bg_height, bg_bits);
    Heltec.display->drawXbm(255 + bgPos, 23, bg_width, bg_height, bg_bits);
    switch (dinosaurState) {
        case 0:
            Heltec.display->drawXbm(0, 11, dinosaur0_width, dinosaur0_height,
                                    dinosaur0_bits);
            break;
        case 1:
            Heltec.display->drawXbm(0, 11, dinosaur1_width, dinosaur1_height,
                                    dinosaur1_bits);
            break;
        case 2:
            Heltec.display->drawXbm(0, 11, dinosaur2_width, dinosaur2_height,
                                    dinosaur2_bits);
            break;
    }
    Heltec.display->display();
}

void setup() {
    Heltec.begin(true /*DisplayEnable Enable*/, true /*Serial Enable*/);

    Heltec.display->flipScreenVertically();
    Heltec.display->setFont(ArialMT_Plain_10);
    lastScreenFlashTime = millis();
    lastDinosaurFlashTime = millis();
    lastBgFlashTime = millis();
}

void loop() {
    if (millis() - lastBgFlashTime >= bgFlashSpeed) {
        lastBgFlashTime = millis();
        bgPos = (bgPos - 1) % bg_width;
    }
    if (millis() - lastDinosaurFlashTime >= dinosaurFlashTime) {
        lastDinosaurFlashTime = millis();
        dinosaurState = (dinosaurState + 1) % 3;
    }

    if (millis() - lastScreenFlashTime >= screenFlashTime) {
        lastScreenFlashTime = millis();
        display();
    }

    while (Serial.available() > 0) {
        int inChar = Serial.read();
        if (isDigit(inChar)) {
            serialTemp += (char)inChar;
        }
        if (inChar == '\n') {
            dinosaurFlashTime = serialTemp.toInt();
            serialTemp = "";
        }
    }
}