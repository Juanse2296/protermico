void initTemperature() {
  sensors.begin();
}

int sensorTemp() {
  sensors.requestTemperatures();
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" Grados Centigrados Crudos");
  float valueTemperature = sensors.getTempCByIndex(0);
  int temperature = (int)round(valueTemperature);  
  return temperature;
}

void printTemperature(int temperature){
  String castTemperature = String(temperature);
  Serial.print(castTemperature);
  Serial.println(" Grados Centigrados Casteados");
  delay(1000);
}

void showTemperature(int temperature) {
  String castTemperature = String(temperature);
  String textTemperature = castTemperature + " " +  (char)247 + "C";
  showInDisplay(3, 20 , 20, textTemperature);
}

