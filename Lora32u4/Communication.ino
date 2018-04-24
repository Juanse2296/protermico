void recieveFromArduino() {
  if (Serial1.available()) {
    char recieved = Serial1.read(); // Read message from arduino
    if (isDigit(recieved))inData += recieved;
    if (recieved == '\n' && inData.length() > 0) { // read the message when user confirm using 'D'
      Serial.print("Recieve from arduino: ");
      Serial.println(inData);
      userStep = 1;
      amount = inData;
      inData = "";
    }
    userActions(recieved);
  }
}

void userActions (char action) {
  switch (action) {
    case 'A':
      Serial.println("Aceptar"); // Confirms the amount to be collected
      if (userStep > 0)  userStep = 2;
      break;
    case 'B':      // Change the information that the user sees on the screen
      if (userStep > 2) {
        if (userStep < 5) {
          userStep += 1;
        }  else {
          userStep = 3;
        }
        Serial.println("Opcion: " + String(userStep));
      }
      break;
  }
}


