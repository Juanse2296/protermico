#include <SoftwareSerial.h>

String inData;

SoftwareSerial serialToLora(2, 3);
void setup() {
  Serial.begin(9600);
  serialToLora.begin(9600);
  while (!Serial) {
    ;
  }
}

void loop() {
  recieve();
}

void recieve() {
  if (serialToLora.available()) {
    char recieved = serialToLora.read();
    inData += recieved;
    if (recieved == '\n') { // Stop to recieve chars
      //Serial.print("Received: ");
      //  Serial.println(inData);
      inData = ""; // Clear recieved buffer
      //delay(500);
    }
  }
}



