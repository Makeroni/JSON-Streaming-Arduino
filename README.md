Data streaming to Arduino for remote RGB led control
====================================================


Emitter
-------

PHP script that streams JSON elements:

```
{ "id" :   1, "value" : 128 },
{ "id" :   2, "value" : 243 },
{ "id" :   3, "value" :  31 },
{ "id" :   1, "value" : 140 },
{ "id" :   2, "value" : 237 },
{ "id" :   3, "value" :  24 },
...
```

Field id represents the analog output to control with values ranging from 0 to 255. JSON elemements have fixed size for easier processing in Arduino.


Receiver
--------------

Arduino program that reads the JSON stream and controls an RGB led using three PWM signals. Data is also sent through serial port for later representation using Processing.


Plotter
-------

Processing program that reads serial data from Arduino and plots some charts.

The system was successfully tested streaming 10 rgb values (30 numbers) per second.

Copyright and license
---------------------

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

See the file `COPYING` in this directory or  http://www.gnu.org/licenses/, for a description of the GNU General Public License terms under which you can copy the files.
