void sendToLora(String message) {
 // Serial.println(message); //for test in monitor
  serialToLora.println(message);
}

void recieve() {
  if (serialToLora.available()) {
    char recieved = serialToLora.read();
    inData += recieved;
    if (recieved == '\n') { // Stop to recieve chars
      Serial.print("Received from lora: ");
      Serial.println(inData);    
       inData = ""; // Clear recieved buffer
    }
  }
}
