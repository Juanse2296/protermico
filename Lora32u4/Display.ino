void initDisplay() {
  screen.begin(SSD1306_SWITCHCAPVCC);
  screen.display();
  showInDisplay(2, 5 , 25, "PROTERMICO");
  delay(2000);
}

void showInDisplay(int textSize, int x, int y, String text) {
  screen.clearDisplay();
  screen.setTextSize(textSize);
  screen.setTextColor(WHITE);
  screen.setCursor(x, y);
  screen.println(text);
  screen.display();
}
/**
   User flow and order interactions with the keyboard or smart phone
*/
void steps(int action) {
  switch (action) {
    case 0:
      showInDisplay(2, 0 , 15, messageToShow);
      break;
    case 1:
      messageToShow = amount + "\n" + "Aceptar?";
      showInDisplay(2, 0 , 15, messageToShow);
      break;
    case 2:
      showInDisplay(2, 0 , 15, "Procesando");
      delay(500);
      userStep = 3;
      break;
    case 3:
      showTemperature(ds_temperature);
      break;
    case 4:
      showInDisplay(2, 10 , 15, "Humedad:  " + String(humidity) + " %");
      break;
    case 5:
      if (resultAlgorithm > 0)  {
        showInDisplay(2, 10 , 15, "Descanzo: " + String(resultAlgorithm) + " min" );
      } else {
        showInDisplay(2, 10 , 15, "No es     necesario descanzar" );
      }
      break;
  }
}

