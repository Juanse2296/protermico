void blueToothRecieve() {
  while (blueTooth.available()) {
    char recieved = blueTooth.read();
    Serial.print("Received from bluetooth: ");
    Serial.println(recieved);

    if (isDigit(recieved) && isDigit(recieved)) {
      message += recieved;
    }
    
    if (recieved == '\n' && message.length() > 0 ) {
      sendToLora();
    }
  }
}

