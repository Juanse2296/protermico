//--------------------------------------------------LIBS
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <SHT1X.h>
#include <SimpleTimer.h>
#include "Countimer.h"

//--------------------------------------------TEMPERATURE
OneWire ourWire(5); // pin for ds sensor
DallasTemperature sensors_DS(&ourWire);

//STH15
SHT1x sht15(2, 3);//Data, SCK
SimpleTimer timer;
float sht_temperature = 0;
float humidity = 0;
float ds_temperature = 0;
int resultAlgorithm = 0;
String currentTime = "0";

//-------------------------------------------- COMMUNICATION

SoftwareSerial serialToArduino(2, 3);
String inData;
String amount = "";
boolean sendMessage = true;

//-------------------------------------------- BUZZER

int buzzer = A0;
int numberOfAerts = 5;
int buzzerState = LOW;
int idTimer;
int idTimerSensors;
boolean allowClang = true;

//-------------------------------------------- COUNTER
Countimer cronometer;
boolean counting = false;
int breakTimeCounter = 4000;
long intervalReadSensors = 3600000;
