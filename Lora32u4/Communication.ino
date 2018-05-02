void recieveFromArduino() {
  while (Serial1.available()) {
    char recieved = Serial1.read(); // Read message from arduino
    if (isDigit(recieved))inData += recieved;
    if (userStep < 2) {
      configurationDevice(recieved);
    }
    userActions(recieved);
  }
}

void configurationDevice (char recieved) {
  if (recieved == '\n' && inData.length() > 0) { // read the message when user confirm using 'D'
   // Serial.print("Recieve from arduino: ");
   // Serial.println(inData);
    userStep = 1;
    amount = inData;
    inData = "";
  }
}


