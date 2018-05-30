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
    timer.enable(idSendToPhone);
  }
  if(!keyPress)timer.run();
}

