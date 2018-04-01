//--------------------------------------------------LIBS
#include <SoftwareSerial.h>
#include <Keypad.h>

//-------------------------------------------- COMMUNICATION
String inData;
SoftwareSerial serialToLora(2, 3);

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
byte rowPins[numRows] = {11,10,9,8}; //Rows 0 to 3
byte colPins[numCols]= {7,6,5,4}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);


