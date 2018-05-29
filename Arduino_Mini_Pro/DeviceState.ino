void phoneMode(char keypressed) {
  if (keypressed == '*' && !activePhone) {
    lcd.clear();
    deviceTemporalState();
    messageToShow = "Conectando con";
    messageToShowTwo = "aplicacion..";
  } else if (keypressed == '*' && activePhone) {
    deviceResume();
  }
  if (keypressed == '*' ) activePhone = ! activePhone ;
}

void deviceTemporalState() {
  messageTemporalOne = messageToShow;
  messageTemporalTwo = messageToShowTwo;
  userStepTemp = userStep;
}

void deviceResume() {
  lcd.clear();
  messageToShow = messageTemporalOne;
  messageToShowTwo = messageTemporalTwo;
  userStep = userStepTemp;
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

