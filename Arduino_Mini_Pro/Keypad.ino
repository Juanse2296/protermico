void keyPressed() {
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)  {
    phoneMode(keypressed);
    if (!activePhone) deviceMode(keypressed);
  }
}

void userFunctions (char keypressed) {
  actionMessage = keypressed;
  sendToLora(keypressed);
  keyPress = true;
  lcd.clear();
  switch (keypressed) {
    case 'A':
      messageToShow = "Temperatura:";
      if (resultAlgorithm.length() < 3)messageToShowTwo = temperature + " grados";
      break;
    case 'B':
      messageToShow = "Humedad: " + humidity + " %";
      break;
    case 'C':
      if (resultAlgorithm.length() > 2) messageToShow = "Descanso: " + resultAlgorithm + " min";
      break;
    case 'D':
      messageToShow = "Recogido:";
      int temporalAmount = amount / 10;
      messageToShowTwo =  String(temporalAmount) + " de " + String(amount);
      break;
  }
}


