/*

 This project -- based on the Arduino demo on "Conditional If-Then statements" -- is a simple
 square wave synthesizer. It's the beginning of my summer experiments in synthesizer design.
 The program reads the state of a potentiometer (an analog input) and does two 
 things with the input: it produces a square wave tone where frequency = the input value from the
 potentiometer (0 - 1023). Second, it varies the brightness of an LED, where higher potentiometer value
 = brighter LED.
 
 This simple input -> output system works because the range of values from the potentiometer 
 corresponds to the raw frequencies most likely to be used in music. As I have removed
 the low end (the synth is silent < 100, so that it can be turned off without the noTone command),
 the Siren Synth has an effective range of 100 Hz to 1023 Hz. (Trust me, you don't want to hear
 a Piezo element at any higher frequency than that...)
 
 Future iterations of this project may experiment with the usable range, attempt to quantize the output
 into a usable gamut, etc. Currently, it's nicknamed the "Siren Synth" because turning the dial up
 and down allows one to imitate a siren's doppler effect. And little else.

 When using a simple piezo disc as a speaker, I recommend taping it to a disposable cup or other
 resonator for increased volume.

 The circuit:
 * potentiometer connected to analog pin 0.
 Center pin of the potentiometer goes to the analog pin.
 side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 13 to ground
 * piezo disc element connected to pin 10 and +5V
 * (note: connecting the piezo element to 3.3V will give the synthesizer a lower, smaller range, from
  100 to ~665 Hz

 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.

Original "Conditional If-Then code":
 created 17 Jan 2009
 modified 9 Apr 2012
 by Tom Igoe

This example code is in the public domain.

http://www.arduino.cc/en/Tutorial/IfStatement

"Siren Synth" code
  created 3 May 2016; updated 21 Feb 2018
  by William O'Hara
  github.com/williamevanohara
  

 */

// These constants won't change:
const int analogPin = A0;    // pin that the sensor is attached to
const int ledPin = 10;       // pin that the LED is attached to
const int buzzerPin = 8;     // pin that the piezo buzzer is attached to
const int threshold = 100;   // an arbitrary threshold level that's in the range of the analog input

void setup() {
  // initialize the LED pin as an output:
  pinMode(buzzerPin, OUTPUT);
  // initialize the piezo element as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);

  // if the analog value is lower than 100, silence the synthesizer. If it is higher, produce sound:
  // output brightness to the LED, on a scale of 0 to 255 (i.e. 1/4 of the potentiometer's range)
  if (analogValue < threshold) {
    noTone(buzzerPin);
    analogWrite(ledPin, analogValue/4);
  } else {
    analogWrite(ledPin, analogValue/4);
    tone(buzzerPin, analogValue);
  }

  // print the analog value:
  Serial.println(analogValue);
  delay(1);        // delay in between reads for stability
}

