int sensorValue; // (A1) anolog Amp sensor
int offSet; // Offset the value from the middle to handle both plus and minus current
const float Vpp = 0.00488758553; // 5v/1023 = Vpp
float voltage; //Voltage reading at sensor
float chargeAmp; //Ampere reading

int voltage


void setup() 


void loop() 
  sensorValue = analogRead(A1);
  offSet = sensorValue - 550;
  voltage = offSet * Vpp
  chargeAmp = voltage / 0.066; // 66 mV/A from datasheet