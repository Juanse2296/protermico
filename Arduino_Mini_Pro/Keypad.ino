
void keyPressed() {
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)  {
    //Serial.println(keypressed);

    if (keypressed == 'D' && message.length() > 0) { // Action for send Message to Lora32u4
      sendToLora();
    }

    if (keypressed == 'A' || keypressed == 'B' ) { // Action for confirm action and Change Options
      message = keypressed;
      sendToLora();
    }

    if (keypressed == 'C') { // clear message
      Serial.println("clear message!");
      message = "";
    }

    if (isDigit(keypressed)) {
      message += keypressed;
    }
  }
}


