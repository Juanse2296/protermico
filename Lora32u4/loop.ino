void loop() {
  recieveFromArduino();
  timer.run();
  cronometer.run();
  if (allowClang) {
    digitalWrite(buzzer, buzzerState);
  } else {
    digitalWrite(buzzer, LOW);
  }
}

