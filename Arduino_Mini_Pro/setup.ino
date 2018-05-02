void setup() {
  constantMillis = 60000;
  serialToLora.begin(9600);
  blueTooth.begin(9600);
  sendTem = false;
  Serial.begin(9600);
  Serial.println("Arduino mini pro");
}

