

#ifndef __NAVIGATION_H__
#define __NAVIGATION_H__


#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#define FORWARD 1
#define REVERSE 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

class Navigation
{
private:
    uint8_t _frontLeftIn1;
    uint8_t _frontLeftIn2;
    uint8_t _frontRightIn1;
    uint8_t _frontRightIn2;
    uint8_t _pwmFrontLeft;
    uint8_t _pwmFrontRight;

    uint8_t _backLeftIn1;
    uint8_t _backLeftIn2;
    uint8_t _backRightIn1;
    uint8_t _backRightIn2;
    uint8_t _pwmBackLeft;
    uint8_t _pwmBackRight;
    uint8_t _speed;

    bool _usesPWM = false;

    forward();
    reverse();
    left();
    right();
    spinLeft();
    spinRight();

public:
    Navigation(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t backRightIn1, uint8_t backRightIn2);
    Navigation(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t pwmFrontLeft, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t pwmFrontRight, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t pwmBackLeft, uint8_t backRightIn1, uint8_t backRightIn2, uint8_t pwmBackRight);
    ~Navigation();
    init(void);
    drive(uint8_t direction);
    drive(uint8_t direction, uint8_t speed);
};

Navigation::Navigation() { }

Navigation::~Navigation() { }

#endif
