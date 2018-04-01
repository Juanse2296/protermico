void initTemperature() {
  sensors_DS.begin();
  sht15_init();
}

float readDsSensor() {
  sensors_DS.requestTemperatures();
  Serial.print("DS18B20 Temp = ");
  Serial.println(sensors_DS.getTempCByIndex(0));
  float valueTemperature = sensors_DS.getTempCByIndex(0);
  //int temperature = (int)round(valueTemperature);
  return valueTemperature;
}

void printTemperature(int temperature) {
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
void sht15_init() {
  pinMode(power, OUTPUT);
  pinMode(gnd, OUTPUT);
  digitalWrite(power, HIGH);
  digitalWrite(gnd, LOW);
}

void readSTH15Sensor()
{
  // Read values from the sensor
  sht_temperature = sht15.readTemperatureC();  
  Serial.print("STH15 Temp = ");
  Serial.print(sht_temperature);
  Serial.println("C");
  humidity = sht15.readHumidity();  
  Serial.print("Humidity = ");
  Serial.print(humidity); 
  Serial.println("%");
}


