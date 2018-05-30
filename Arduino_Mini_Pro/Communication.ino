void sendToLora(char message) {
  if (!serialToLora.available())serialToLora.println(message);
}

void recieveFromLora() {
  serialToLora.listen();
  while (serialToLora.available() > 0) {
    char recieved = serialToLora.read();
    if (isDigit(recieved))inData += recieved;
    if (recieved == '\n' && inData.length() > 0) { // read the message when user confirm using 'D'
      if (keyPress) {
        generateMessage(actionMessage, inData);
      } else {
        switch (valueOption) {
          case 1:
            temperature = inData;
            sendTemperatureToBluetooth();
            valueOption = 0;
            break;
          case 2 :
            resultAlgorithm = inData;
            restTime(resultAlgorithm);
            valueOption = 0;
            break;
        }
        gettingData = false;
      }
      inData = "";
    }
  }
}

void getInformationOne() {

  valueOption = 1;
  sendToLora('A');

}

void getInformationTwo() {
  valueOption = 2;
  sendToLora('C');
}
