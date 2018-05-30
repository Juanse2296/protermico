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
      temperature = temporalData;
      break;
    case 'B':
      humidity = temporalData;
      break;
    case 'C':
      resultAlgorithm = temporalData;
      break;
  }
  keyPress = false;
}

