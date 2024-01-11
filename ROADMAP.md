## EdgieD Development Roadmap

### Right Now

Currently, EdgieD simply detetcts a Rising or Falling Edge. It doesn't do pulse stretching or constraining. It can be used for the detection of edges in code that does do this, but my aim is to add a timeout() method, an input variable to allow/block retriggering with block as the default as well as some time division and multiplication functions, too.

The full details of what it does presently are...
  * detect an edge state change based on...
    * included ```Rising``` (value = ```true```) and ```Falling``` (value = ```false```),
    * the optional ```edge``` input variable (default is the ```Rising``` macro and)
    * the required ```test``` variable (this must always be populated when calling the ```detect()``` method)
  * if an edge state change is detetcted it outputs the value edge, thus, 
    * if detecting a ```Falling``` ```edge```, the output will be ```false``` when detected but ```true``` at all other times
    * if detecting a ```Rising``` ```edge```, the output will be ```true``` when detected but ```False``` at all other times

### Looking To The Future

It's my plan add the above-mentioned ```timeout()``` method next. In the project I'm using EdgieD for right now, I need an output pulse of a set width, which cannot be retriggered until released from the current input. I'm currently using [Chrono, by Sofian Audrey and Thomas Ouellet Fredericks](https://github.com/SofaPirate/Chrono) to handle the output pulsewidth timing. It would be more efficient, and easier coding to be able to handle timoeouts within the same library. So, here are the functions I want to develop...
  * ```bool edge::timeout(uint32_t pulsewidth)``` - returns ```!edge``` if timout has passed. The reason for returning ```!edge``` is to be able to us the edge state as a trigger output and it's opposite as the timeout. Thus an output pulse variable can be set and unset directly by detection and timeout.
  * ```uint32_t edge::period()``` - returns the microseconds between edge detections, which is useful for frequency multiple and division functions. As an example of what I need this for, I want to create a MIDI/DynSync/TapTempo "Babel Fish" master clock for my other passion, my music. EdgieD will be essential for reading and timing the selected master input of the 3 systems and sync all systems, such as drum machine, looper pedal, etc, to playback from Logic Pro or, and this is especially where DynSync comes in, playback from my Zoom L-12 audio workstation.
  * ```float edge::frequency(float multi)``` - returns a frequency value based on ```period()```, with the default being the one-to-one reciprocal of period or, by passing a value via the ```multi``` float, halve (multi = 0.5) or double (multi = 2) the frequency calculated from ```period()``` by ```frequency()```, maintaining close to perfect synchronisation to the trigger edge input. In the the mentioned use case of MIDI to DynSync or back, convert 24 pulse per quarter note (48Hz) input to 48ppqn (96Hz) or 96ppqn (192Hz), or back on an output at less than a percent or 2 flutter. That's what musicians call "SWING"!

  Doing all this in pure C code, rather than assembly will make the EdgieD library useful in a broader range of platforms, from 8 bit microcontrollers, like I'm tinkering with, to DAW plugins (beyond my "hacking" skills) and everything in between.

  ### Contribution & Commercial Use

  Contribs are welcome! I'm working on nearly a dozen different workshop projects right now, only 2 of which are EdgieD and TriggerBounce. Much of what I'm fiddling with is in the workshop, not the laptop so, left to my own devices, this roadmap may be a mountain bike ride down the "[Gunbarrel Hwy](https://en.wikipedia.org/wiki/Gunbarrel_Highway)." Feel free to open issues or make pull requests. Most of you likely know way more about C++ than me. Forks and ports to other languages are also welcome. However, if you plan is to make money from any usage, read the licence, it's only restriction is, "if my code is profitable to you, I get to profit, too. I won't abide bludgers." For all other applications, it's free.