# LED Multi Mode
This is adapted from a [tutorial](https://www.ladyada.net/learn/arduino/lesson5.html) provided by [adyada.net](http://ladyada.net). 

Pushing the button will toggle between three modes for the built-in LED as well as the optional LED wired to output d13.

The modes are:
- Off
- On
- Blinking

The circuit used is relatively straight forward though there are a couple considerations.

The 100Ω resistor prevents short circuits of d2 if the pin is accidentally set as a LOW output rather than an input. The 10kΩ resistor serves as a pull-down resistor to assure the d2 voltage drops to zero when the button is not pressed.

The circuit used is publicly available on [circuit-diagram.org](https://crcit.net/c/2e76e24e17d6461cb04c18589ec5993f/):

![led mode circuit](./circuit.svg)