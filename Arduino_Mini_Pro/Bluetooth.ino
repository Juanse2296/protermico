void blueToothRecieve() {
  blueTooth.listen();
  while (blueTooth.available() > 0) {
    dataBluethooth = blueTooth.readString();
    if (dataBluethooth != NULL) {
      //      Detiene el envio de todos los posibles datos
      if (dataBluethooth == "stop") {
        sendTemperature = false;
      }
      if (dataBluethooth == "start") {
        sendTemperature = true;
      }
      // Metodo que valida la conexion entre protermico y smartphone, cuando el dato entrante es = c
      if (dataBluethooth == "c") {
        connectionOn();
      }
      // Metodo que ejecuta el tiempo de descanso en milisegundos y lo envia al dispositivo movil, el dato = w es solo una demostración, el codigo debe ir en los condicionales
      //Que ejecutan el descanso.
      if (dataBluethooth == "w") {
        restTime(3);
      }
    }
  }
}

void sendTemperatureToBluetooth() {
  Serial.println("entra al sendTemp");
  int temp = 26;
  blueTooth.print("/" + String(temp) + "~");
  blueTooth.println();
}

void connectionOn() {
  Serial.println("entra al connection On");
  blueTooth.print("#success~");
  blueTooth.println();
  activePhone = false;
  sendTemperature = true;
  deviceResume();
}
void restTime(int minute) {
  //  Serial.println("entra al restTime");
  //  int timeInMillis = minute * constantMillis;
  //  blueTooth.print("*rest+" + String(timeInMillis) + "~");
  //  blueTooth.println();
  //  delay(1000);
  sendTemperature = true;
}
