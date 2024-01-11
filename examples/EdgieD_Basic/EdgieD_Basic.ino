//     ### STATE CHANGE (EDGE DETECTION) EXAMPLE ###
//  _____________________________________________________________________
//  Can read a signal from an input or a function to precisely trigger an 
//  action on either a rising or falling edge. Useful for detecting the 
//  instant value changes, such as for synchronising an output sine wave 
//  to an input square wave, to name a case.
//  ©2024 Crunchysteve, see LICENSE for uage terms.
//  http://github.com/crunchysteve/EdgieD
//  Proudly developed and tested in VS Code and Wokwi.com

//  This is a basic Rising (aka leading) edge detector. To change it to a
//  Falling (aka trailling) edge detector, change the method call
//  'myEdge.detect(token)' to 'myEdge.detect(token,Falling)'

#include <EdgieD.h>             //  import library to do edge detection

bool token = false;             //  Initialise state variable for a system clock

uint32_t backThen = 0;          //  Initialise variable to hold previous clock time
uint32_t period = 500;          //  Initialise variable to set clock toggle period

Edge myEdge;                    //  Instantiate the EdgieD library as "myEdge"

void setup() {                  //  Arduino setup function
  Serial.begin(115200);         //  Start serial conection at 114200 baud
  pinMode(LED_BUILTIN, OUTPUT); //  Configure the builtin LED (13) as an output
}

void loop() {                                       // main program loop
  uint32_t rightNow = millis();         //  <-|
  if(rightNow - backThen > period){     //    |
    token = !token;                     //    |-  start a software squarewave
    backThen = rightNow;                //    |
  }                                     //  <-|

  digitalWrite(LED_BUILTIN,myEdge.detect(token));   //  Lights up LED when pulse is detected
                                                    //  also takes macros 'Rising' or 'Falling'
                                                    //  optionally after token

  delay(20);                                        //  20mS delay to make the LED visible
                                                    //  Would leave this out in normal usage
}
