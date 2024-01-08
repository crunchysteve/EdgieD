//  EdgieD Library, Written by Crunchysteve, 19 September, 2022.
//  Based on the button edge detection tutorial at
//  https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection
//  but generalised for working with variables and other coded binary state
//  changes. It can read digital inputs to detect a button state change, 
//  the output state of a timer or the output states of other custom libraries.
//  
//  This example detects the "leading edge" (as pressed) of a button, attached
//  between pin 2 and ground, not changing output state again until released, 
//  then pressed again.

#include <EdgieD.h>       //  Include the library in the code.

int buttonPin = 2;        //  Use pin 2 in INPUT_PULLUP mode for the button.
int buttonState = 0;      //  Variable to contain the state of the button.
int oldButtonState = 0;   //  Variable to contain the previous button state.
int edge = TRAILING;      //  As we're using pinMode INPUT_PULLUP, we're
                          //  actually going from logic HIGH to logic LOW,
                          //  so our "LEADING" edge is actually TRAILING.
                          //  Library macros...
                          //  LEADING = HIGH or true logic macros, while
                          //  TRAILING = LOW or false logic macros.

int ledPin = LED_BUILTIN; //  Use the built in LED on the board. (Pin 13, Uno)
int ledState = LOW;       //  Initialise 

Edge myEdge;              //  Declare an instance to use for detecting edges.
                          //  You might want an instance for each button, 
                          //  signal or changing variable that you want to 
                          //  precicely measure a LEADING or TRAILING edge of.

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT_PULLUP);  //  Set digital pin 2 to INPUT_PULLUP mode.
  pinMode(ledPin,OUTPUT);           //  Set the led pin to output mode
  Serial.begin(115200);             //  Start the serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin); //  Read the button pin.
                                    //  Detect the state change of the button.
  if(myEdge.detect(buttonState,oldButtonState,TRAILING)){
    ledState = !ledState;           //  If the buttonState has changed,
                                    //  change the LED state. "!" = "invert."
    Serial.print("The LED state is ");
    Serial.println(ledState);       //  Print the state of the LED.
  }
  oldButtonState = myEdge.oldState; //  Store the latest button reading
  digitalWrite(ledPin,ledState);    //  Write the ledState to the LED
}
