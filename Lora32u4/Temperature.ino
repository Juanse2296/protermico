void initTemperature() {
  sensors_DS.begin();
  readSensors();
  timer.setInterval(15000, readSensors);
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
