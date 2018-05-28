void initTemperature() {
  sensors_DS.begin();
  readSensors();
  timer.setInterval(10000, readSensors);
  idTimer = timer.setInterval(3000, Clang);
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
  readSTH15Sensor();
  breakTime(ds_temperature, sht_temperature);
}
