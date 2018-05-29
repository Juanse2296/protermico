void keyPressed() {
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)  {
    switch (userStep) {
      case 1:
        stepOne(keypressed);
        break;
      case 2:
        stepTwo(keypressed);
        break;
      case 3:
        userStep = 4;
        break;
      case 4:
        messageToShowTwo = "";
        userFunctions (keypressed);
        break;
    }
  }
}

void userFunctions (char keypressed) {
  actionMessage = keypressed;
  sendToLora(keypressed);
  //  Serial.println(keypressed);
  switch (keypressed) {
    case 'A':
      //      Serial.println("Get temperature: ");
      break;
    case 'B':
      //      Serial.println("Get humedity: ");
      break;
    case 'C':
      //      Serial.println("Get breakTiem: ");
      break;
    case 'D':
      //      Serial.println("Show amount");
      lcd.clear();
      messageToShow = "Rocogido:";
      int temporalAmount = amount / 10;
      messageToShowTwo = String(temporalAmount)  + " de " + String(amount);
      break;
  }
}


