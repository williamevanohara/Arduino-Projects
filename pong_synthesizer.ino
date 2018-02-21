/*
  Pong Synthesizer v 1.0

  The "PONG Synthesizer" is designed to recreate the soundtrack of 
  the famous Atari game "PONG" (1972). This simple synth produces
  two tones--a low one for strikes of the ball, and a high one
  for goals. The synth also lights an LED to indicate a goal.


  Pieces:
  Arduino (I use an UNO)
  breadboard
  two pushbuttons
  piezo speaker (with attached red & black wires, or with two female-to-male wires)
  small LED
  two (2) 10k ohm resistors
  one (1) 220k resistor
  four short patch wires (in my build these are blue, green, yellow, & orange)
  two short red patch wires
  two short black patch wires
  one long red wire
  one long black wire


 
  Circuit diagram forthcoming



  created January 29, 2018
  by William O'Hara <http://www.williamohara.net>
  williamevanohara@gmail.com

  This code is licensed CC-BY-NC-SA <http://creativecommons.org/licenses/by-nc-sa/4.0/> 

*/

// setting pin numbers
const int lowbuttonPin = 2;     // the pin number the blue "paddle/wall" button is plugged into
const int highbuttonPin = 8;     // the pin number the green "goal" button is plugged into
const int ledPin = 9;     // the number of the "goal" LED pin
const int piezoPin = 12;     // the number of the piezo speaker's pin


// setting null values for both buttons
int lowbuttonState = 0;
int highbuttonState = 0;

void setup() {
  // initialize the speaker and LED pins as outputs:
  pinMode(piezoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
 
  // initialize the button pins as inputs:
  pinMode(lowbuttonPin, INPUT);
  pinMode(highbuttonPin, INPUT);
}

void loop() {
  // read the state of both buttons:
  
  highbuttonState = digitalRead(highbuttonPin);
  lowbuttonState = digitalRead(lowbuttonPin);

// check to see if the high button is pressed. if it is, light LED and play high octave sound, then cancel both

 if (highbuttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone(piezoPin, 440, 500);
    delay(500);
    noTone(piezoPin);
    digitalWrite(ledPin, LOW);
    
  } 

  // check to see if low button is pressed. if it is, play low octave sound, then cancel it

  if (lowbuttonState == HIGH) {
    tone(piezoPin, 220, 200);
    delay(200);
    noTone(piezoPin);
    
  } 
  
  
}
