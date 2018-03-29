void initDisplay() {
  screen.begin(SSD1306_SWITCHCAPVCC);
  screen.display();
  showInDisplay(2, 5 , 25, "PROTERMICO");
  delay(2000);
}

void showInDisplay(int textSize, int x, int y, String text) {
  screen.clearDisplay();
  screen.setTextSize(textSize);
  screen.setTextColor(WHITE);
  screen.setCursor(x, y);
  screen.println(text);
  screen.display();
}

void printText() {
  String s;
  if (Serial.available()) {
    s = Serial.readString();
    screen.println(s);
    screen.display();
    screen.println("\n");
  }
  delay(4000);
}
