void loop() {
  int temperature = sensorTemp();  
  printTemperature(temperature);
  showTemperature(temperature);
  toClang(temperature);
}
