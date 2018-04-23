void breakTime(float ds_temperature, float sht_temperature) {
  float C = 0.7 * THN(ds_temperature) + 0.2 * TG(sht_temperature) + 0.1 * TA(sht_temperature);
  int A = 33; 
  int B = 27; 
  int D = 28;
  int ft = ((A - B) / ((C - D) + (A - B))) *  60;
  if (ft < 60) {
    int result = (int)60 - ft;
    Serial.print("Descanzo: ");
    Serial.print(result);
    Serial.println(" min por hora");     
  } else{
    Serial.println("No es necesario");
  }
  delay(250); 
}


float THN(float temperature) {
  return 0.4207 * temperature + 14.876;
}

float TG(float temperature) {
  return 2.668 * temperature - 55.1695;
}

float TA(float temperature) {
  return 0.6927 * temperature + 11.5695;
}

