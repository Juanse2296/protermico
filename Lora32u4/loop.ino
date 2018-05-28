void loop() {
  recieveFromArduino();
  timer.run();
  digitalWrite(buzzer, buzzerState);
  cronometer.run();
}

