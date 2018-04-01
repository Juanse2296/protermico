void setup() {
  serialToLora.begin(9600);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
}

