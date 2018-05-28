void sendToLora(char message) {
  serialToLora.println(message);
}

void recieveFromLora() {
  serialToLora.listen();
  while (serialToLora.available() > 0) {
    char recieved = serialToLora.read();
    if (isDigit(recieved))inData += recieved;


    if (recieved == '\n' && inData.length() > 0) { // read the message when user confirm using 'D'
      Serial.println(inData);
      generateMessage(actionMessage, inData);
      inData = "";
    }
    
    
    
  }
}
