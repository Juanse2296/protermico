void setup()   {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(buzzer, OUTPUT);
  initTemperature();
}
