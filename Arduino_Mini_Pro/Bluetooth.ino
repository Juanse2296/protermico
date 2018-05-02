void blueToothRecieve() {
  if (blueTooth.available()) {
    Serial.println(blueTooth.read());
    dataBluethooth = blueTooth.readString();
    Serial.print("Received from bluetooth: ");
    Serial.println(dataBluethooth);
    if (dataBluethooth != NULL) {
      Serial.println("entra al dato");
      if (dataBluethooth == "c") {
        blueTooth.print("#");
        blueTooth.print("success");
        blueTooth.print('~');
        blueTooth.println();
        sendIt = true;
      } else {
        Serial.println("no es el comando");
      }
    }
  }

  if (Serial.available()) // Si llega un dato por el monitor serial se envía al puerto BT
  {
    //blueTooth.write(Serial.read());
    //blueTooth.print("Prueba");
  }
}

void sendData(String info) {
  //blueTooth.write(info);
  blueTooth.print(info);
  blueTooth.println('~');
  delay(10);
}

