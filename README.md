RGB led using Arduino and JSON streaming
========================================


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

Field id represents the analog output with values from 0 to 255. JSON elemements have same size for later parsing in Arduino.


Controller
----------

Arduino program that reads the remote JSON stream and controls an RGB led using three PWM signals. Data is also pass through serial port for later representation using Processing. Arduino was able to receive up to 10 rgb values per second.


Plotter
-------

Processing program that reads serial data from Arduino and plots.


Copyright and license
---------------------

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

See the file `COPYING` in this directory or  http://www.gnu.org/licenses/, for a description of the GNU General Public License terms under which you can copy the files.
