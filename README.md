rgb-network
===========

Control RGB led remotely

FILES
------

1.- arduino/rgb_network_serial

reads values from the serial port like:
pin_id,value[0-100]

creates a PWM signal in the selected pin
input values [0-100] are mapped to [0-255]


2.- PHP File index.php

writes JSON with an array of values 
control_id,control_value

control_id: identifier of the control
control_value: a value [0-100]


