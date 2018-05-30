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
  //  Serial.println(keypressed);
  switch (keypressed) {
    case 'A':
      //            Serial.println("Get temperature: ");
      break;
    case 'B':
      //            Serial.println("Get humedity: ");
      break;
    case 'C':
      //            Serial.println("Get breakTiem: ");
      break;
    case 'D':
      //           Serial.println("Show amount");
      lcd.clear();
      messageToShow = "Recogido:";
      int temporalAmount = amount / 10;
      messageToShowTwo =  String(temporalAmount) + " de " + String(amount);
      break;
  }
}


