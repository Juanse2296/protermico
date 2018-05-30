void blueToothRecieve() {
  blueTooth.listen();
  while (blueTooth.available() > 0) {
    dataBluethooth = blueTooth.readString();

    String valOne = getValue(dataBluethooth, '+', 0);
    String valTwo = getValue(dataBluethooth, '+', 1);
    if (dataBluethooth != NULL) {
      //      Detiene el envio de todos los posibles datos
      if (dataBluethooth == "stop") {
        sendTemperature = false;
      }
      if (valOne == "start") {
        sendTemperature = true;
        activePhone = false;
        deviceResume();
      }
      // Metodo que valida la conexion entre protermico y smartphone, cuando el dato entrante es = c
      if (dataBluethooth == "c") {
        connectionOn();
      }
      // Metodo que ejecuta el tiempo de descanso en milisegundos y lo envia al dispositivo movil, el dato = w es solo una demostración, el codigo debe ir en los condicionales
      //Que ejecutan el descanso.
      if (dataBluethooth == "w") {
        //        restTime(3);
      }
    }
  }
}

void sendTemperatureToBluetooth() {
  blueTooth.print("/" + temperature + "~");
  blueTooth.println();
}

void connectionOn() {
  blueTooth.print("#success~");
  blueTooth.println();
}
void restTime(String minute) {
  if (minute.toInt() > 0 && minute.length() > 2) {
    int timeInMillis = minute.toInt() * constantMillis;
    blueTooth.print("*rest+" + String(timeInMillis) + "~");
    blueTooth.println();
  }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
