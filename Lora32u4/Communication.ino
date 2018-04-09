void initCommunication() {
  Serial1.begin(9600);
}
void recieve() {
  while (Serial1.available()) {
    char recieved = Serial1.read();
    inData += recieved;
    if (recieved == '\n') {
      Serial.print("Recieve from arduino: ");
      Serial.println(inData);
      inData = "";
    }
  }
}

