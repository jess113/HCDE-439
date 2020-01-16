/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

const int buttonPin = 7;     // the pushbutton pin
const int R = 11;           // the PWM pin the RGB LED is attached to
const int G = 10;           // the PWM pin the RGB LED is attached to
const int B = 9;           // the PWM pin the RGB LED is attached to

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

// the setup routine runs once when you press reset:
void setup() {
  // initialize pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // initialize R pin as an output:
  pinMode(R, OUTPUT);
  // initialize G pin as an output:
  pinMode(G, OUTPUT);
  // initialize B pin as an output:
  pinMode(B, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop (){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // for-loop fading effect for R pin (set to the beat of Three Degrees Summer by Philanthrope)
    for(int i = 0; i < 146;i++){
      // set the brightness of pin:
      analogWrite(R, i);
      // wait for 10 milliseconds to see the fading effect 
      delay(10);
    }

    //repeat for-loop for G pin
    for(int i = 0; i < 146;i++){
      analogWrite(G, i); 
      delay(10);
    }

    //repeat for-loop for B pin
    for(int i = 0; i < 146;i++){
      analogWrite(B, i);
      delay(10);
    }  
  } else {
    // turn LED off:
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
}
