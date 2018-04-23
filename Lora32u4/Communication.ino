void recieveFromArduino() {
  if (Serial1.available()) {
    char recieved = Serial1.read();
        
    if (isDigit(recieved))inData += recieved;
    if (recieved == '\n' && inData.length() > 0) {
      Serial.print("Recieve from arduino: ");
      Serial.println(inData);
      inData = "";
    }
    
    if (recieved == 'A') {
       Serial.println("Aceptar");
       userStep += 1;
    }
  }
 delay(100);
}


