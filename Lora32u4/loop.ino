void loop() {
  float ds_temperature = readDsSensor();
  readSTH15Sensor();
  breakTime(ds_temperature, sht_temperature);
  //showTemperature(ds_temperature);
  steps(userStep);
  delay(500);
}

