void setup()   {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Init LoRa32u4 Ra-02");
  initDisplay();
  initTemperature();
  Scheduler.startLoop(recieveFromArduino);
}



