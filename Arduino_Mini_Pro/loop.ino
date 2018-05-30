void loop() {
  keyPressed();
  showInDisplay();
  if (activePhone) {
    blueToothRecieve();
  } else {
    recieveFromLora();
    userConfiguration();
  }
  if (sendTemperature) {
    timer.run();
  }
}

