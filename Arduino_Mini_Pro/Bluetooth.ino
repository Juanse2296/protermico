void blueToothRecieve() {
  if (blueTooth.available()) {
    dataBluethooth = blueTooth.readString();
    Serial.print("Received from bluetooth: ");
    Serial.println(dataBluethooth);
    if(dataBluethooth != NULL){
      if(dataBluethooth == "c"){
        blueTooth.print("#");
        blueTooth.print("success");
        blueTooth.print('~');
        blueTooth.println();
        Serial.println("llega: " + dataBluethooth);
        sendIt = true;
      }else{
        Serial.println("no es el comando");
      }
    }
  }
}

