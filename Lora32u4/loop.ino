void loop() {
  timer.run(); // Interval for read sensors
  recieveFromArduino();
  steps(userStep);
}

