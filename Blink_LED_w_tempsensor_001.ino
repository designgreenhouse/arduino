/* experiment för att testa och lära hur man läser analog och digital input, samt sätter en digital utgång 
 och skriver ut ett analogt värde. 
 
komponenter
* Arduino R3
* tinkerkit sensorshield
* tinkerkit LED
* tinkerkit pushbutton
* tinkerkit temperatur sensor
 Lars Lindmark, Design Greenhouse 2015
*/

// constants won't change. They're used here to
const int sensorIn = A0;  // temperatursensor (middle terminal) connected to tinkerkit O0
const int buttonPin = A1; // the number of the pushbutton pin
const int ledO0 = 11;     // select the pin for the tinkerLED
const int pin13 = 13;     // select the pin for the outputLED

// variables will change:
int sensorValue = 0;      // variable to store the value coming from the tempsensor
int buttonState = 0;      // variable for reading the pushbutton status
int outputValue = 0;      // value output to the PWM (analog out)

void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT); // initialize digital pin 13 as an output. 
  pinMode(11, OUTPUT); // initialize digital pin 11 as an output O0 on thinkercad.
  pinMode(A0,INPUT); // initialize analog pin a0 as an input O0 on thinkercad.
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input:
  Serial.begin(9600); // initialize serial communications at 9600 bps:

}

void loop() {
  
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value:

 // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {  
    // turn yellow LED  on:
  digitalWrite(11, HIGH); // set LED on
  delay(1000); // wait for a second
  digitalWrite(11,LOW); // set LED off
  delay(1000); // wait for a second
}
  else {
    // turn green LED on:
  digitalWrite(13, HIGH); // set LED on
  delay(1000); // wait for a second
  digitalWrite(13,LOW); // set LED off
  delay(1000); // wait for a second
  }
    sensorValue = analogRead(sensorIn);  // read the value from the sensor:
    outputValue = map(sensorValue, 0, 1023, 0, 255); // map it to the range of the analog out:
 
  //omvandla sensorvärde till temperatur i grader Celsius
  
 
  // print the results to the serial monitor:
  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
}
