rgb-network
===========

Control RGB led remotely

FILES
------

1.- PHP 

writes an stream of JSON elements with data values 
id,value

id: identifier of the control
value: a value [0-128]


2.- Arduino

reads values from the serial port like:
pin_id,value[0-1128]

creates a PWM signal in the selected pin
input values [0-128] are mapped to [0-255]

Writes r,g,b values in the serial port


3.- Processing
 
Reads serial port and plots the values
Red, green, blue and the mix of them.

