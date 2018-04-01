void blueToothRecieve(){
  if(blueTooth.available()){
   char recieved = blueTooth.read();
   Serial.print("Received from bluetooth: ");
   Serial.println(recieved);
  }
}

