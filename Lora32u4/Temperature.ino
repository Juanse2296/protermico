void initTemperature() {
  sensors_DS.begin();
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

void readSTH15Sensor(){
  // Read values from the sensor
  sht_temperature = sht15.readTemperatureC();
  /*Serial.print("STH15 Temp = ");
  Serial.print(sht_temperature);
  Serial.println("C");*/
  humidity = sht15.readHumidity();
  /*Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println("%");*/
}


