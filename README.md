# dinosaurInEsp8266
运行在ESP8266上的仿chrome小恐龙的游戏机

![效果图](https://i.loli.net/2021/01/12/ofxLGBl3uwyH8Ac.jpg)
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fasjdf%2FdinosaurInEsp8266.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2Fasjdf%2FdinosaurInEsp8266?ref=badge_shield)



直接用的~~heltec的现成的~~TTGO的ESP8266+SSD1306模块（128*32像素）

因为屏幕高度不足，所以把障碍物（仙人掌压缩了）如果移植到标准的0.96寸oled上面的话，可以自己去images.h替换小号仙人掌，大号仙人掌已经转换好了。

如果你用的是heltec的模块的话，~~直接烧录即可~~按照heltec的电路改程序，按键引脚是D6脚（也可以使用板子上已有的PRG脚），如需更改请前往main.ino中的define修改。

如果是普通的esp8266（nodemcu）和SSD1306，请~~按照项目下的WIFI_Kit_8_Pinout_Diagram.pdf连接。~~自己焊接完了以后去程序改

有问题请提issue，我会尽快解决。
