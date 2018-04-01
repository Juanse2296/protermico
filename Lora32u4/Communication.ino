void initCommunication(){
  serialToArduino.begin(9600);
}


void recieve() {
  if (serialToArduino.available()) {
    char recieved = serialToArduino.read();
    inData += recieved;
    if (recieved == '\n') { // Stop to recieve chars
      Serial.print("Received from arduino: ");
      Serial.println(inData);
      inData = ""; // Clear recieved buffer
      //delay(500);
    }
  }
}

