/*
 * Generalised edge detection library by Crunchysteve
 * Created 19 September, 2022 and derived from the Arduino button edge detector tutorial,
 * generalising it to work with variables as well is input signal state changes.
 * released under an MIT licence
 */

#ifndef EdgeDetector_h
  #define EdgeDetector_h

  #include "Arduino.h"

  #define LEADING 1
  #define TRAILING 0

  class Edge{

    private:
      int state;
      int oldState;
      int edge;

    public:
      Edge();
      int detect(int state, int oldState, int edge);
  };

#endif
