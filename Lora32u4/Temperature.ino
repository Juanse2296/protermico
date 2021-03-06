void initTemperature() {
  sensors_DS.begin();
  readDsSensor();
  readSTH15Sensor();
  idTimerSensors = timer.setInterval(intervalReadSensors, readSensors);
  idTimer = timer.setInterval(breakTimeCounter, Clang);
  timer.setInterval(10000, readSTH15Sensor);
  timer.disable(idTimer);
}

void readDsSensor() {
  sensors_DS.requestTemperatures();
  ds_temperature = sensors_DS.getTempCByIndex(0);
}

void readSTH15Sensor() {
  sht_temperature = sht15.readTemperatureC();
  humidity = sht15.readHumidity();
}

void readSensors() {
  readDsSensor();
  breakTime(ds_temperature, sht_temperature);
}
