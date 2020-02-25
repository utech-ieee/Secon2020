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
