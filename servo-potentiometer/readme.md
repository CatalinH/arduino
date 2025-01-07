# Arduino Uno - Control servo with potentiometer
Components and code

## Components
- Arduino Uno with cable to connect to pc
- Micro Servo motor SG90 180 degrees
- B10K potentiometer (linear)
- breadboard
- 6 dupont wires

## Pin connection
- DP-2 - servo signal (left - yellow)
- P-5V - servo power (middle - red)
- P-GND - servo ground (left - brown)
- A0 - potentiometer (middle - knob)
- P-5V - potentiometer positive (right)
- P-GND - potentiometer ground (left)

(DP - digital pin / A - analog / P - power)

## Steps
- Connect components
- Copy servo-potentiometer.ino file
- Select Arduino board and com port
- Upload

## Info
In this scenario, potentiometer acts as a power divider and will vary the voltage on the wiper (middle).

Sketch uses 2070 bytes (6%) of program storage space. Maximum is 32256 bytes.
Global variables use 50 bytes (2%) of dynamic memory, leaving 1998 bytes for local variables. Maximum is 2048 bytes.

![Arduino controlling a servo motor with a potentiometer](board-servo-potentiometer.jpg)

## Helpers
- https://www.youtube.com/watch?v=QbgTl6VSA9Y
- https://github.com/arduino-libraries/Servo/tree/master/examples/Knob
- https://www.youtube.com/watch?v=sWbSeJmUFfw
