//     ### STATE CHANGE (EDGE DETECTION) EXAMPLE ###
//  _____________________________________________________________________
//  Can read a signal from an input or a function to precisely trigger an 
//  action on either a rising or falling edge. Useful for detecting the 
//  instant value changes, such as for synchronising an output sine wave 
//  to an input square wave, to name a case.
//  ©2024 Crunchysteve, see LICENSE for uage terms.
//  http://github.com/crunchysteve/EdgieD
//  Proudly developed and tested in VS Code and Wokwi.com

#ifndef EDGE_H              //  Ensure library is prototyped only once
  #define EDGE_H

    #define Rising  1       //  Define the Rising and Falling macros
    #define Falling 0

    #include "Arduino.h"    //  Include the Arduino framework

    class Edge {            //  Prototype the Constructor method
      public:
          explicit Edge();
                            //  Prototype the detect method & input variables
          bool detect(bool test, bool edge = Rising);

      private:              //  Declare the private variables
          bool test;
          static bool previousTest;
          bool edge;

    };

#endif                      //  End definition of library prototype
