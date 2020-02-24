#include <Navigation.h>

.
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
