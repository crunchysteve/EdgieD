//     ### STATE CHANGE (EDGE DETECTION) EXAMPLE ###
//  _____________________________________________________________________
//  Can read a signal from an input or a function to precisely trigger an 
//  action on either a rising or falling edge. Useful for detecting the 
//  instant value changes, such as for synchronising an output sine wave 
//  to an input square wave, to name a case.
//  ©2024 Crunchysteve, see LICENSE for uage terms.
//  http://github.com/crunchysteve/EdgieD

#include "Arduino.h"                      //  include necessary arduino frameworks
#include "EdgieD-1.0.0.h"                       //  include library prototype

bool Edge::previousTest = Rising;         //  initialise previous test to false

Edge::Edge() {                            //  Constructor Method
    this->test = test;                    //  localise inputs to instances
    this->previousTest = previousTest;
    this->edge = edge;

}

bool Edge::detect(bool test, bool edge) { //  the 'detect' method, edge is LEADING by default
  if (test != previousTest){              //  if the input state has changed
    previousTest = test;                  //  store the new state as our new previousTest
    if(test == edge){                     //  if input state equals our chosen edge state
      return edge;                        //  return the edge we're testing for
    }
                                          //  otherwise, if no edge match...
    return !edge;                         //  return the opposite to the edge we're testing for
  } else {
                                          //  also, if no input state change
    return !edge;                         //  return the opposite to the edge we're testing for
  }
}
