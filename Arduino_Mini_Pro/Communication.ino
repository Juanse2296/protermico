void sendToLora() {   
  Serial.print("sent to Lora: ");
  Serial.println(message); //for test in monitor
  serialToLora.println(message);
  message = "";
}

