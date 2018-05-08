//--------------------------------------------------LIBS
#include <SoftwareSerial.h>
#include <Keypad.h>

#include <LiquidCrystal_I2C.h>

//-------------------------------------------- DISPLAY

LiquidCrystal_I2C lcd(0x27,16,2);  
String messageToShow = "Protermico";
char actionMessage = "";

//-------------------------------------------- COMMUNICATION
String inData;
SoftwareSerial serialToLora(12, 13);
SoftwareSerial blueTooth(10, 11);
String dataBluethooth = "";
char character;
boolean sendTem;
static int constantMillis;
unsigned long interval = 2000;
unsigned long previousMillis = 0;

//--------------------------------------------Keypad 

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

