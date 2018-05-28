void initDisplay() {
  lcd.init();
  lcd.backlight();
}
void showInDisplay() {
  lcd.setCursor(0, 0);
  lcd.print(messageToShow);
}

void generateMessage(char option, String data) {
  lcd.clear();
  switch (actionMessage) {
    case 'A':
      messageToShow = "Temperatura: " + data + " grados";
      break;
    case 'B':
      messageToShow = "Humedad: " + data + " %";
      break;
    case 'C':
      messageToShow = "Descanso: " + data + " min";
      break;
  }
}

