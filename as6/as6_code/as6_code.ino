 int ledPin = 8;                  // LED connected to digital pin 8
 int VRx = 0;                     // joystick slider variable connecetd to analog pin 0
 int VRy = 1;                     // joystick slider variable connecetd to analog pin 1
 int SW = 7;                       // joystick switch connected to digital pin 7
 int valueX = 0;                  // variable to read sensor value from the analog pin 0
 int valueY = 0;                  // variable to read sensor value from the analog pin 1
 int valueSW = 1;                 // variable to read sensor value from the digital pin 7

 // setup code to run once
 void setup() {
  Serial.begin(9600);             // initialize serial communications
  pinMode(ledPin, OUTPUT);        // initialize LED pin as output
  pinMode(SW,INPUT);         // initialize switch pin as output
  digitalWrite(SW,HIGH);
  Serial.setTimeout(10);          // set the timeout for parseInt
 }

 // function to map sensor data to numbers suitable for canvas drawing
 int treatValue(int data) {
  return data = map(data, 0, 1023, 0, 400);
 }

 // main code to run repeatedly
 void loop() {
  // read sensor values of the variable resistors
  valueX = analogRead(VRx);            
  valueY = analogRead(VRy);
  valueSW = digitalRead(SW); // read the push button input pin

  if (Serial.available()) {          // check if there is serial data 
    digitalWrite(ledPin, LOW);       // turn off LED
  } else {                           // if no serial data is received
    if ((valueX >= 494 && valueX <= 504) && (valueY >= 504 && valueY <= 514)) { // turn LED on when moving joystick
      digitalWrite(ledPin, LOW);    // LED remains off when in joystick in resting position (estimated [494-504, 504-514])
    } else {
      digitalWrite(ledPin, HIGH);   // LED on when joystick not in resting position
    }
  }
  
  // send an array of the two values to serialport
  Serial.print('[');
  Serial.print(treatValue(valueX));
  Serial.print(',');
  Serial.print(treatValue(valueY));
  Serial.print(',');
  Serial.print(valueSW);
  Serial.println(']');            // write last bracket followed by ‘\r’ carriage return and ‘\n’ line feed characters
 }
