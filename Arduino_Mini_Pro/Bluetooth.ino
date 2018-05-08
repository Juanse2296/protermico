void blueToothRecieve() {
  blueTooth.listen();
  unsigned long currentMillis = millis();
  while (blueTooth.available()) {
    dataBluethooth = blueTooth.readString();
    Serial.print("Received from bluetooth: ");
    Serial.println(dataBluethooth);
    if (dataBluethooth != NULL) {
      //      De tiene el envio de todos los posibles datos
      if (dataBluethooth == "stop") {
        sendTem = false;
      }
      if (dataBluethooth == "start") {
        sendTem = true;
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

  if (Serial.available()) // Si llega un dato por el monitor serial se envía al puerto BT
  {
    //blueTooth.write(Serial.read());
    //blueTooth.print("Prueba");
  }
  //El envio de la temperatura puede quedar establecido cada 1 o 2 minutos, pero para efectos de muestra puede quedar cada 5 segundos.
  //  cambiar la variable interval para deicidir el tiempo en segundos.
  if ((unsigned long)(currentMillis - previousMillis) >= interval && sendTem) {
    sendTemp(26);
    previousMillis = millis();
  }
}

void sendTemp(int temp) {
  Serial.println("entra al sendTemp");
  blueTooth.print("/" + String(temp) + "~");
  blueTooth.println();
}

void connectionOn() {
  Serial.println("entra al connectionOn");
  blueTooth.print("#success~");
  blueTooth.println();
}
void restTime(int minute) {
  Serial.println("entra al restTime");
  int timeInMillis = minute * constantMillis;
  blueTooth.print("*rest+" + String(timeInMillis) + "~");
  blueTooth.println();
  delay(1000);
  sendTem = true;
}
