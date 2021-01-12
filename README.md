# dinosaurInEsp8266
运行在ESP8266上的仿chrome小恐龙的游戏机

![效果图](https://i.loli.net/2021/01/12/ofxLGBl3uwyH8Ac.jpg)



直接用的heltec的现成的ESP8266+SSD1306模块（128*32像素）

因为屏幕高度不足，所以把障碍物（仙人掌压缩了）如果移植到标准的0.96寸oled上面的话，可以自己去images.h替换小号仙人掌，大号仙人掌已经转换好了。

如果你用的是heltec的模块的话，直接烧录即可，按键引脚是D3脚，如需更改请前往main.ino中的define修改。

如果是普通的esp8266（nodemcu）和SSD1306，请按照项目下的WIFI_Kit_8_Pinout_Diagram.pdf连接。

有问题请提issue，我会尽快解决。

