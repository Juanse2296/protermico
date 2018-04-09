
void keyPressed() {
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)  {
    //Serial.println(keypressed);

    if (keypressed == 'D' && message.length() > 0) { // sending message to lora
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


