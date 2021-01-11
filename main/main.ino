#include "heltec.h"  // alias for `#include "SSD1306Wire.h"`
#include "images.h"
#define FPS 25
#define BGSPEED 100  //背景每秒走的格子数
#define CACTI 100    //背景每秒走的格子数
String serialTemp = "";

int gameStart = 1;
int jump = 0;   // 初始化跳跃
int bgPos = 0;  // 背景偏移
int dinosaurHeight = 11;
long long lastDinosaurFlashTime;
long long lastBgFlashTime;
long long lastScreenFlashTime;
long long lastCactiFlashTime;
long long lastDinosaurHeightFlashTime;
long long lastObstacleCreateTime;
int screenFlashTime = 1000 / FPS;   // 屏幕的刷新时间间隔
int bgFlashSpeed = 1000 / BGSPEED;  // 背景的刷新时间间隔ms
int cactiFlashTime = 1000 / CACTI;  // 仙人掌的刷新时间间隔ms
int dinosaurFlashTime = 100;        // 小恐龙的刷新时间间隔 单位ms
int dinosaurHeightFlashTime = 30;   // 小恐龙高度的刷新时间间隔
int obstacleCreateTime = 500;  // 最短的障碍物生成间隔 防止难度过高
int dinosaurState = 0;
// 11格 1.5s走完上下全程
//小恐龙跳跃高度随时间变化数组（狗头 不想用加速度计算）
int dinosaurHeightPos[] = {0,  1,  2,  3,  5,  6,  7,  8,  9,  10, 10,
                           11, 11, 12, 12, 12, 12, 12, 12, 11, 11, 10,
                           10, 9,  8,  7,  6,  5,  3,  2,  1};
int cactiPos[128 + cacti_width] = {
    0};  // 仙人掌位置 0位置的时候仙人掌应该在屏幕之外
void display() {
    Heltec.display->clear();
    // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
    // on how to create xbm files
    Heltec.display->drawXbm(bgPos, 23, bg_width, bg_height, bg_bits);
    Heltec.display->drawXbm(255 + bgPos, 23, bg_width, bg_height, bg_bits);
    switch (dinosaurState) {
        case 0:
            Heltec.display->drawXbm(0, dinosaurHeight, dinosaur0_width,
                                    dinosaur0_height, dinosaur0_bits);
            break;
        case 1:
            Heltec.display->drawXbm(0, dinosaurHeight, dinosaur1_width,
                                    dinosaur1_height, dinosaur1_bits);
            break;
        case 2:
            Heltec.display->drawXbm(0, dinosaurHeight, dinosaur2_width,
                                    dinosaur2_height, dinosaur2_bits);
            break;
    }
    for (int i = 0; i < 128 + cacti_width; i++) {
        if (cactiPos[i]) {
            Heltec.display->drawXbm(i - cacti_width, 19, cacti_width,
                                    cacti_height, cacti_bits);
        }
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
    lastCactiFlashTime = millis();
    lastObstacleCreateTime = millis();
    lastDinosaurHeightFlashTime = millis();
    Serial.println("game start");
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
    if (jump > 0 &&
        millis() - lastDinosaurHeightFlashTime >= dinosaurHeightFlashTime) {
        lastDinosaurHeightFlashTime = millis();
        jump--;
        dinosaurHeight = 11 - dinosaurHeightPos[jump];
    }
    if (millis() - lastCactiFlashTime >= cactiFlashTime) {
        lastCactiFlashTime = millis();
        for (int i = 0; i < 127 + cacti_width; i++) {
            cactiPos[i] = cactiPos[i + 1];
        }
    }

    if (gameStart && millis() - lastObstacleCreateTime >= obstacleCreateTime) {
        // 随机生成障碍物
        obstacleCreateTime = random(1000, 2000);
        lastObstacleCreateTime = millis();
        cactiPos[126 + cacti_width] = 1;
    }

    while (Serial.available() > 0) {
        int inChar = Serial.read();
        if (isDigit(inChar)) {
            serialTemp += (char)inChar;
        }
        if (inChar == '\n') {
            jump = serialTemp.toInt();
            serialTemp = "";
        }
    }
    if (millis() - lastScreenFlashTime >= screenFlashTime) {
        lastScreenFlashTime = millis();
        display();
    }

    // 判断是否碰撞障碍物
    int hasObstacle = 0;
    for (int i = cacti_width; i < cacti_width + cacti_width; i++) {
        hasObstacle += cactiPos[i];
    }
    if (gameStart && hasObstacle) {
        if (dinosaurHeightPos[jump] < cacti_height) {
            // gameStart = 0;
            Serial.print(millis());
            Serial.println(" game over");
        }
    }
}