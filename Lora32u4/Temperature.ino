void initTemperature() {
  sensors_DS.begin();
  readSensors();
  timer.setInterval(15000, readSensors);
}

float readDsSensor() {
  sensors_DS.requestTemperatures();
  float valueTemperature = sensors_DS.getTempCByIndex(0);
  return valueTemperature;
}

void showTemperature(int temperature) {
  String castTemperature = String(temperature);
  String textTemperature = castTemperature + " " +  (char)247 + "C";
  showInDisplay(3, 20 , 20, textTemperature);
}

void readSTH15Sensor() {
  sht_temperature = sht15.readTemperatureC();
  humidity = sht15.readHumidity();
}

void readSensors() {
  if (!startToClang && !Serial1.available()) {
    ds_temperature = readDsSensor();
    readSTH15Sensor();
    breakTime(ds_temperature, sht_temperature);
  }
}
