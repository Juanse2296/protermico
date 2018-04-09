void setup()   {
  Serial.begin(9600);
  initCommunication();
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Init LoRa32u4 Ra-02!");
  initDisplay();
  initTemperature();
}

