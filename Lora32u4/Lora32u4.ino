//------------------------------------------------- -LIBRERIAS
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <SHT1X.h>

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
DallasTemperature sensors_DS(&ourWire); //Se instancia la librería DallasTemperature

//STH15
SHT1x sht15(A2, A3);//Data, SCK
float sht_temperature = 0;
float humidity = 0;
int power = A1;
int gnd = A0;

//-------------------------------------------- BUZZER

const int buzzer = 0;

//-------------------------------------------- Communication

SoftwareSerial serialToArduino(2, 3);
String inData;

//--------------------------------------------- Algorith variables


