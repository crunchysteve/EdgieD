[Discuss the code or seek support for any of my code projects at my discussions page.](https://github.com/crunchysteve/crunchysteve.github.io/discussions)
***
# EdgieD Library v1.0
##### Crunchysteve, &copy;2022.

Based on the button edge detection tutorial at...
https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection
but generalised for working with variables and other coded binary state
changes. It can read digital inputs to detect a button state change, the 
state change of a variable during runtime, the output state of a timer or 
the output states of other custom libraries.

The included example detects the "leading edge" (as pressed) of a button, 
attached between pin 2 and ground, not changing output state again until 
released, then pressed again.

### How It Works
This custom library compares the states of an input, a variable or output 
from another custom library with the previously measured state and whether 
the edge is leading or trailing, to precisely time function calls to the 
edge of a frequently changing state. By passing the current state, the 
previous state (as variables) and the preferred edge (via custom macros, 
LEADING and TRAILING) to a decalred instance of the library 
(eg "myEdge.detect(state,oldState,LEADING)" to detect a leading/rising 
edge), one can time other functions precise to the moment of the state 
change with no more than normal Arduino latencies. The code is basic C++ with 
now hardware specific calls, so it should work an anything from an Adafruit 
to a Wio and beyond.

For example...
  * Include the EdgieD library header, <EdgieD.h>, 
  * initialise an instance, Edge myEdge;, 
  * then call the instance, ```if(myEdge.detect(current,previous,LEADING){ //  do something }``` 
    * (if a rising edge has been detected, the functions inside the if statement run)
  * after the instance runs, set oldState to the currently tested state, ready for the next test.

EdgieD is non-blocking and only takes as long as its lines of code to run.

The [Quick Start](https://github.com/crunchysteve/EdgieD/wiki/Quick-Start) guide is available on the Wiki, as is the more detailed [Documentation](https://github.com/crunchysteve/EdgieD/wiki/Documentation).

### Licence
The EdgieD Library is free software, please see ["LICENCE"](https://github.com/crunchysteve/EdgieD/blob/main/LICENSE). for more details.
