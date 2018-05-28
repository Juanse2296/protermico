void keyPressed() {
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)  {
    actionMessage = keypressed;
    sendToLora(keypressed);
      Serial.println(keypressed);
    switch (keypressed) {
      case 'A':
        Serial.println("Get temperature: ");
        break;
      case 'B':
        Serial.println("Get humedity: ");
        break;
      case 'C':
        Serial.println("Get breakTiem: ");
        break;
    }
  }
}



