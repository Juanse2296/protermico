void loop() {
  if(userStep > 2) timer.run(); // Interval for read sensors
  recieveFromArduino();
  steps(userStep);
  if(startToClang){
    toClang();
  }
}

