void keyPressed() {
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)  {
    phoneMode(keypressed);
    if (!activePhone) deviceMode(keypressed);
  }
}
String messageTemporalOne = "";
String messageTemporalTwo = "";
int userStepTemp = 0;
void phoneMode(char keypressed) {
  if (keypressed == '*' && !activePhone) {
    lcd.clear();
    Serial.print("mode: ");
    Serial.println(activePhone);
    messageTemporalOne = messageToShow;
    messageTemporalTwo = messageToShowTwo;
    userStepTemp = userStep;
    messageToShow = "Conectando con";
    messageToShowTwo = "aplicacion..";
  } else if (keypressed == '*' && activePhone) {
    lcd.clear();
    messageToShow = messageTemporalOne;
    messageToShowTwo = messageTemporalTwo;
    userStep = userStepTemp;
  }
  if (keypressed == '*' ) activePhone = ! activePhone ;
}
void deviceMode(char keypressed) {
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
      if (!activePhone) userFunctions (keypressed);
      break;
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
      messageToShow = "Recogido:";
      int temporalAmount = amount / 10;
      messageToShowTwo =  String(temporalAmount) + " de " + String(amount);
      break;
  }
}


