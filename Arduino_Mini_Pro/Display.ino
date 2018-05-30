void initDisplay() {
  lcd.init();
  lcd.backlight();
}

void showInDisplay() {
  lcd.setCursor(0, 0);
  lcd.print(messageToShow);
  lcd.setCursor(0, 1);
  lcd.print(messageToShowTwo);
}

void generateMessage(char option, String temporalData) {
  lcd.clear();
  switch (actionMessage) {
    case 'A':
      messageToShow = "Temperatura:";
      messageToShowTwo = temporalData + " grados";
      break;
    case 'B':
      messageToShow = "Humedad: " + temporalData + " %";
      break;
    case 'C':
      messageToShow = "Descanso: " + temporalData + " min";
      break;
  }
}

