void loop() {
  if (userStep > 2 && !startToClang) timer.run(); // Interval for read sensors
  recieveFromArduino();
  if (startToClang) {
    toClang();
  } else {
    steps(userStep);
  }
}

