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

void steps(int action) {
switch(userStep){
  case 0:
  showInDisplay(2, 0 , 15, "Juan");
  break;
  case 1:
  showInDisplay(2, 0 , 15, "Sebastian");
  break;
  case 2:
  showInDisplay(2, 0 , 15, "Reina");
  break;
}
}

