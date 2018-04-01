#include <SoftwareSerial.h>

String inData;
const int buzzer = 13;

SoftwareSerial serialToLora(2, 3);
void setup() {
  //Serial.begin(9600);
  pinMode(0, OUTPUT);  
  //digitalWrite(buzzer,HIGH);
  serialToLora.begin(9600);
 /* while (!Serial) {
    ;
  }*/
}
void clang() {
  tone(0, 1000);
 // delay(1000);
//  noTone(0);
 // delay(500);
}
void loop() {
 recieve();
 //sendToLora("test");
}

void sendToLora(String message) {
 // Serial.println(message); //for test in monitor
  serialToLora.println(message);
}

void recieve() {
  if (serialToLora.available()) {
    char recieved = serialToLora.read();
    inData += recieved;
    if (recieved == '\n') { // Stop to recieve chars
     // Serial.print("Received from lora: ");
     // Serial.println(inData);
     
      //delay(500);
      if(inData=="a"){
        digitalWrite(buzzer,HIGH);
      }else if(inData=="b"){
        digitalWrite(buzzer,LOW);
      }
       inData = ""; // Clear recieved buffer
    }
  }
}



