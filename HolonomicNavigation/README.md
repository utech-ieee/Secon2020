# Robot-Control-Library
This is C++ library for Arduino for controlling various motors of the same type simultaneously(Servo motor, DC motor, Stepper Motor) on a robot

## Installation

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries folder.

When installed, this library should look like:

Arduino/lib/targets/libraries/HolonomicNavigation                   (this library's folder)<br>
Arduino/lib/targets/libraries/HolonomicNavigation/HolonomicNavigation.cpp  (the library implementation file)<br>
Arduino/lib/targets/libraries/HolonomicNavigation/HolonomicNavigation.h    (the library description file)<br>
Arduino/lib/targets/libraries/HolonomicNavigation/keywords.txt      (the syntax coloring file)<br>
Arduino/lib/targets/libraries/HolonomicNavigation/examples          (the examples in the "open" menu)<br>

## Building

After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select Test.  This will add a corresponding line to the top of your sketch:
#include <HolonomicNavigation.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "MotorControl.o" will appear
in "Arduino/lib/targets/libraries/HolonomicNavigation". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "HolonomicNavigation.cpp" or "HolonomicNavigation.h"),
then you must first 'unbuild' this library by deleting the "HolonomicNavigation.o" file. The
new "HolonomicNavigation.o" with your code will appear after the next press of "verify"

## Usage
Four Wheel Control:
```c++
#include <HolonomicNavigation.h>

const uint8_t frontLeftIn1 = 1;
const uint8_t frontLeftIn2 = 2;
const uint8_t frontRightIn1 = 3;
const uint8_t frontRightIn2 = 4;
const uint8_t backLeftIn1 = 5;
const uint8_t backLeftIn2 = 6;
const uint8_t backRightIn1 = 7;
const uint8_t backRightIn2 = 8;

FourWheelNavigation robot(frontLeftIn1, frontLeftIn2, frontRightIn1, frontRightIn2, backLeftIn1, backLeftIn2, backRightIn1, backRightIn2);

void setup()
{
    robot.init();
}

void loop()
{
    robot.drive(FORWARD);
    delay(1000);
    robot.drive(REVERSE);
}
```
