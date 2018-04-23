void setup() {
  serialToLora.begin(9600);
  blueTooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Arduino mini pro");
}

