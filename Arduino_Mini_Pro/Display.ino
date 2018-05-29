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

void generateMessage(char option, String data) {
  lcd.clear();
  switch (actionMessage) {
    case 'A':
      messageToShow = "Temperatura:";
      messageToShowTwo = data + " grados";
      break;
    case 'B':
      messageToShow = "Humedad: " + data + " %";
      break;
    case 'C':
      messageToShow = "Descanso: " + data + " min";
      break;
  }
}

