void setup() {
  serialToLora.begin(9600);
  blueTooth.begin(9600);
  Serial.begin(9600);
  initDisplay();
  idSendToPhone=timer.setInterval(intervalSendTemperature, sendTemperatureToBluetooth);
  timer.disable(idSendToPhone);
  timer.setInterval(2000, getInformationOne);
  timer.setInterval(3000, getInformationTwo);
  constantMillis = 60000;
}
