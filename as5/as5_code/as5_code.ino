const int buttonPin = 2; // pin number for push button
const int potPin = 0; // pin number for sensing potentiometer
int brightness = 0; // variable indicating brightness

void setup() {
  Serial.begin(9600);  // initialize the serial for communication  
}

void loop() {
  int button = digitalRead(buttonPin); // read from the button
  int potValue = analogRead(potPin); // read from the potentiometer 
  brightness = map(potValue, 0, 1023, 0, 255); // map the value from potentiometer to the brightness 
  // control the brightenss based on the sensor value
  Serial.println(brightness); // write the brightness to the serial port  
  delay(50); // delay 50 milliseconds 
  Serial.println(button); // write the button state to the serial port
  delay(50); // delay 50 milliseconds 
}
