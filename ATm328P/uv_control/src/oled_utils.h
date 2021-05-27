//Headers
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void oled_init(){
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
    display.clearDisplay();
}
void oled_text(String txt_, int x, int y, int size){
    display.setTextSize(size);
    display.setTextColor(WHITE);
    display.setCursor(x, y);
    display.print(txt_);
}
void oled_clear(){
    display.clearDisplay();
}

void oled_update(){
    display.display();
}
