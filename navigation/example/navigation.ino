#include "../Navigation.h"

Navigation robot(1, 2, 3, 4, 5, 6, 7, 8);

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