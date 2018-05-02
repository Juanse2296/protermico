void breakTime(float ds_temperature, float sht_temperature) {
  float C = 0.7 * THN(ds_temperature) + 0.2 * TG(sht_temperature) + 0.1 * TA(sht_temperature);
  int A = 33;
  int B = 27;
  int D = 28;
  int ft = ((A - B) / ((C - D) + (A - B))) *  60;
  if (ft < 60) {
    resultAlgorithm = (int)60 - ft;
    userStep = 5;
    startToClang = true;
  } else {
    startToClang = false;
    resultAlgorithm = 0;
  }

  Serial.println("Tiempo de descanzo: " + String(resultAlgorithm) + " min");
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

void userActions (char action) {
  switch (action) {
    case 'A':
      Serial.println("Aceptar"); // Confirms the amount to be collected
      if (userStep == 1)  userStep = 2;
      if (userStep > 2)  startToClang = false;
      if (userStep > 2 && startToClang)  startToClang = false;
      break;
    case 'B':      // Change the information that the user sees on the screen
      if (userStep > 2) {
      if (userStep > 2 && !startToClang) {
        if (userStep < 6) {
          userStep += 1;
        }  else {
          userStep = 3;
        }
        Serial.println("Opcion: " + String(userStep));
      }
      break;
  }
}
