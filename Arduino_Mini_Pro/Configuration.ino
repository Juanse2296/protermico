void userConfiguration () {
  switch (userStep) {
    case 0:
      messageToShow = "PROTERMICO,";
      messageToShowTwo = "Bienvenido";
      delay(3000);
      userStep = 1;
      break;
    case 1:
      messageToShow = "Cantidad a";
      messageToShowTwo = "recolectar?";
      break;
    case 2:
      messageToShowTwo = "Cont= A, Borr= B";
      break;
    case 3:
      messageToShow = "A= Temp, B= Hume";
      messageToShowTwo = "C= Desc, D= Trab";
      break;
    case 4:
      // Keep this case clean
      break;
  }
}

void stepOne (char keypressed) {
  if (isDigit(keypressed)) {
    userStep = 2;
    lcd.clear();
    messageToShow = "";
    messageToShow += keypressed;
  }
}

void stepTwo(char keypressed) {
  if (isDigit(keypressed)) {
    messageToShow += keypressed;
  }
  if (keypressed == 'A') {
    amount = messageToShow.toInt();
    userStep = 3;
  }
  if (keypressed == 'B' && userStep == 2) {
    lcd.clear();
    messageToShow = messageToShow.substring(0, messageToShow.length() - 1);
  }
}

