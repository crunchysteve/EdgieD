[Discuss the code or seek support for any of my code projects at my discussions page.](https://github.com/crunchysteve/crunchysteve.github.io/discussions)
***
# EdgieD Library v1.0.0
##### Crunchysteve, &copy;2024.
##### Proudly developed in [VS Code](https://code.visualstudio.com/), by an Apple fanboi, and tested in [Wokwi](Wokwi.com)

Captain's Log (supplemental): Just tried to understand Arduino's Library Manager submission process, in order to get this WORKING update to replace the original BROKEN one and I can't even submit a removal of the library. JESUS! This is why I switched to PlatformIO as my editor. Not only does it have more features, it's actually project focused in how you set it up and adding a third-party, custom library is simply a matter of adding that library's git URL to platformio.ini as a lib-dep. Sorry, ArduinoIDE peeps, You'll have to install this working version manually, from now on.

## Quick Install
For most people, download [this zip file](https://github.com/crunchysteve/EdgieD/releases/download/ArduinoLibrary-update/EdgieD_1.0.0.zip), open **ArduinoIDE**, open the ```Sketch/Include Library/Add .ZIP Library``` menu, navigate to where you downloaded the zip, and click "Install."

For **PlatformIO**, update ```~/[your_project/]/platformio.ini``` lib_deps parammeter to include ```https://github.com/crunchysteve/EdgieD-1.0.0.git```

## What is EdgieD?
Loosely based on the button edge detection tutorial at...
https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection

...but generalised for working with variables and other coded binary state changes. It can read digital inputs to detect a button state change, the state change of a variable during runtime, the output state of a timer or the output states of other custom libraries.

The included example detects the default "leading edge" (as pressed) of a button, attached between pin 2 and ground, not changing output state again until released, then pressed again.

It can be used for...
  1. timing functions to repeat on a trigger input,
  2. debouncing input buttons (use delay() around 5 to 20mS in your test "if()")
  3. synchronising output signals to input signals, such as triggering a sinusoid function to run one phase, in sync with the triggering edge of the input. (I'll add that as an example sketch soon, hopefully.)

These are just a few examples!

### How It Works
EdgieD compares the states of an input, a variable or output from another function  with the previously measured state and whether the edge is leading or trailing, to precisely time function calls to the edge of a frequently changing state. By passing the current state, the previous state (as variables) and the preferred edge (via custom macros, LEADING and TRAILING) to a decalred instance of the library (eg "myEdge.detect(state,oldState,LEADING)" to detect a leading/rising edge), one can time other functions precise to the moment of the state change with no more than normal Arduino latencies. The code is basic C++ with now hardware specific calls, so it should work an anything from an Adafruit to a Wio-Terminal and beyond.

### How To Use It In Your Code
  * Include the EdgieD library header, <EdgieD.h>, 
  * initialise an instance, Edge myEdge;, 
  * then call it, ```if(myEdge.detect(test_value,Rising){ //  do something }``` 
    * if a Rising edge has been detected, the functions inside the if statement runs,
    * "Rising" is the default state and this parameter can be left out for rising edges,
  * the previous edge state is held in a private static variable inside each instance

See the included example, EdgieD_Basic.ino for more details.

EdgieD is non-blocking and only takes as long as its lines of code to run.

The [Quick Start](https://github.com/crunchysteve/EdgieD/wiki/Quick-Start) guide is available on the wiki, as is the more detailed [Documentation](https://github.com/crunchysteve/EdgieD/wiki/Documentation) and feature roadmap.

### Licence
The EdgieD Library is free software, please see ["LICENCE"](https://github.com/crunchysteve/EdgieD/blob/main/LICENSE). for more details.
