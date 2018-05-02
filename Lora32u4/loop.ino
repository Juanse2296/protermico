void loop() {
  recieveFromArduino();
  if (userStep > 2) timer.run(); // Interval for read sensors
  if (userStep > 2 && startToClang && !Serial1.available()) {
    toClang();
  } else if ( !Serial1.available()) {
    steps(userStep);
  }
}

