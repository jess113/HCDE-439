 int ledPin = 8;
 int joyPinX = 0;                 // slider variable connecetd to analog pin 0
 int joyPinY = 1;                 // slider variable connecetd to analog pin 1
 int valueX = 0;                  // variable to read the value from the analog pin 0
 int valueY = 0;                  // variable to read the value from the analog pin 1

 void setup() {
  pinMode(ledPin, OUTPUT);              // initializes digital pins 0 to 7 as outputs
  Serial.begin(9600);
 }

 int treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }

 void loop() {
  // reads the value of the variable resistor
  valueX = analogRead(joyPinX);  
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(100);            
  // reads the value of the variable resistor
  valueY = analogRead(joyPinY);  

  digitalWrite(ledPin, HIGH);          
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  Serial.print('[');
  Serial.print(treatValue(valueX));
  Serial.print(',');
  Serial.print(treatValue(valueY));
  Serial.println(']');
 }
