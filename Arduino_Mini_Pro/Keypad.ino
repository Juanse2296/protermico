void keyPressed(){
   char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)  {
    Serial.print(keypressed);
  }
}

