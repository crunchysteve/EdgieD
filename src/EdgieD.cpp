/*
 * Generalised edge detection library by Crunchysteve
 * Created 19 September, 2022 and derived from the Arduino button edge detector tutorial,
 * generalising it to work with variables as well is input signal state changes.
 * released under an MIT licence
 */

#include "Arduino.h"
#include "EdgieD.h"

Edge::Edge(){
  
}

int Edge::detect(int state, int oldState, int edge){
  this->state = state;
  this->oldState = oldState;
  this->edge = edge;
  
  if(state != oldState && state == edge){
    return true;
  } else {
    return false;
  } 
}
