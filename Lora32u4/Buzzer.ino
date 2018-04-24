void clang() {
  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
  delay(500);
}

void toClang(int temperature) {
  if (temperature > 32) {
    clang();
  }
}

