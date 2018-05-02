void setup() {
  serialToLora.begin(9600);
  blueTooth.begin(9600);
  sendIt = false;
  Serial.begin(9600);
  Serial.println("Arduino mini pro");
}

