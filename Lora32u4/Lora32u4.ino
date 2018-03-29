//------------------------------------------------- -LIBRERIAS
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//-------------------------------------------------- -DISPLAY SMALL
// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 screen(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//--------------------------------------------TEMPERATURE
OneWire ourWire(1); //Se establece el pin declarado como bus para la comunicación OneWire
DallasTemperature sensors(&ourWire); //Se instancia la librería DallasTemperature

//-------------------------------------------- BUZZER

const int buzzer = 0;
