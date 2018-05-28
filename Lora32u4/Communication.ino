void recieveFromArduino() {
  while (Serial1.available()) {
    char recieved = Serial1.read();
    handleRequest(recieved);
    Serial.println(recieved);
    // generateMessage(sht_temperature);
  }
}

void sendToArduino(String message) {
  if (sendMessage) {
    Serial.print("sent to Arduino: ");
    Serial.println(message); //for test in monitor*/
    while (!Serial1.available() && sendMessage) {
      Serial1.print(message);
      Serial1.println('\n');
    }
  }
}

void generateMessage(float value) {
  String temporalMessage = String((int)value);
  sendToArduino(temporalMessage);
}

void handleRequest(char option) {
  sendMessage = true;
  if (option == 'A') generateMessage(sht_temperature);
  if (option == 'B') generateMessage(humidity);
  if (option == 'C') sendToArduino(currentTime);
  sendMessage = false;
}

