// 背景
#define bg_width 256
#define bg_height 10
const unsigned char bg_bits[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF0, 0x00, 0x70, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x0F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xFC, 0x03, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x80,
    0x03, 0x00, 0xF0, 0xFF, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0x07, 0x00, 0xF0, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0xF0, 0x07,
    0x1C, 0x00, 0x00, 0x00, 0xFC, 0x03, 0x00, 0x00, 0xFC, 0xFF, 0x1F, 0x00,
    0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFC, 0xFF, 0x1F,
    0x00, 0x00, 0xFC, 0xFF, 0x00, 0xFC, 0x0F, 0x00, 0xE0, 0xFF, 0xFF, 0xFF,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x00, 0x04, 0x18, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x78,
    0x00, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1C, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x40, 0x28, 0x48, 0x00,
    0x84, 0x00, 0x04, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x20,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x0C, 0xC8, 0x00, 0x00, 0x30, 0x00, 0x30,
    0xC0, 0x01, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

// // 仙人掌
// #define cacti_width 10
// #define cacti_height 20
// const unsigned char cacti_bits[] PROGMEM = {
//     0x38, 0x00, 0x38, 0x00, 0xB8, 0x01, 0xB8, 0x01, 0xB8, 0x01,
//     0xB8, 0x01, 0xB8, 0x01, 0xBB, 0x01, 0xBB, 0x01, 0xFB, 0x00,
//     0x7B, 0x00, 0x3B, 0x00, 0x3B, 0x00, 0x3B, 0x00, 0x3E, 0x00,
//     0x3C, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00,
// };
// 小号仙人掌
#define cacti_width 11
#define cacti_height 11
const unsigned char cacti_bits[] = {
    0x20, 0x00, 0x60, 0x00, 0x72, 0x04, 0x73, 0x06, 0x73, 0x06, 0x73,
    0x06, 0x7F, 0x06, 0xFE, 0x07, 0xF0, 0x03, 0x70, 0x00, 0x73, 0x00,
};

// 恐龙
#define dinosaur0_width 20
#define dinosaur0_height 20
const unsigned char dinosaur0_bits[] PROGMEM = {
    0x00, 0xF8, 0x07, 0x00, 0xFC, 0x0F, 0x00, 0xEC, 0x0F, 0x00, 0xFC, 0x0F,
    0x00, 0xFC, 0x0F, 0x00, 0x7C, 0x00, 0x01, 0xFC, 0x03, 0x01, 0x1E, 0x00,
    0x83, 0x1F, 0x00, 0xE7, 0x7F, 0x00, 0xFF, 0x5F, 0x00, 0xFF, 0x1F, 0x00,
    0xFE, 0x1F, 0x00, 0xFC, 0x1F, 0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x07, 0x00,
    0x60, 0x06, 0x00, 0x20, 0x04, 0x00, 0x20, 0x04, 0x00, 0x60, 0x0C, 0x00,
};

#define dinosaur1_width 20
#define dinosaur1_height 20
const unsigned char dinosaur1_bits[] PROGMEM = {
    0x00, 0xF8, 0x07, 0x00, 0xFC, 0x0F, 0x00, 0xEC, 0x0F, 0x00, 0xFC, 0x0F,
    0x00, 0xFC, 0x0F, 0x00, 0x7C, 0x00, 0x01, 0xFC, 0x03, 0x01, 0x1E, 0x00,
    0x83, 0x1F, 0x00, 0xE7, 0x7F, 0x00, 0xFF, 0x5F, 0x00, 0xFF, 0x1F, 0x00,
    0xFE, 0x1F, 0x00, 0xFC, 0x1F, 0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x05, 0x00,
    0x60, 0x04, 0x00, 0x20, 0x0C, 0x00, 0x20, 0x00, 0x00, 0x60, 0x00, 0x00,
};

#define dinosaur2_width 20
#define dinosaur2_height 20
const unsigned char dinosaur2_bits[] PROGMEM = {
    0x00, 0xF8, 0x07, 0x00, 0xFC, 0x0F, 0x00, 0xEC, 0x0F, 0x00, 0xFC, 0x0F,
    0x00, 0xFC, 0x0F, 0x00, 0x7C, 0x00, 0x01, 0xFC, 0x03, 0x01, 0x1E, 0x00,
    0x83, 0x1F, 0x00, 0xE7, 0x7F, 0x00, 0xFF, 0x5F, 0x00, 0xFF, 0x1F, 0x00,
    0xFE, 0x1F, 0x00, 0xFC, 0x1F, 0x00, 0xF8, 0x0F, 0x00, 0x30, 0x07, 0x00,
    0x20, 0x06, 0x00, 0x60, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0C, 0x00,
};
