#include "Navigation.h"

Navigation::Navigation(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t backRightIn1, uint8_t backRightIn2) : _frontLeftIn1(frontLeftIn1), _frontLeftIn2(frontLeftIn2), _frontRightIn1(frontRightIn1), _frontRightIn2(frontRightIn2), _backLeftIn1(backLeftIn1), _backLeftIn2(backLeftIn2), _backRightIn1(backRightIn1), _backRightIn2(backRightIn2)
{
  _usesPWM = false;
}

DC_Motor::DC_Motor(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t pwmFrontLeft, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t pwmFrontRight, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t pwmBackLeft, uint8_t backRightIn1, uint8_t backRightIn2, uint8_t pwmBackRight) : _frontLeftIn1(frontLeftIn1), _frontLeftIn2(frontLeftIn2),  _pwmFrontLeft(pwmFrontLeft), _frontRightIn1(frontRightIn1), _frontRightIn2(frontRightIn2), _pwmFrontRight(pwmFrontRight),_backLeftIn1(backLeftIn1), _backLeftIn2(backLeftIn2), _pwmBackLeft(pwmBackLeft), _backRightIn1(backRightIn1), _backRightIn2(backRightIn2), _pwmBackRight(pwmBackRight)
{
  _usesPWM = true;
}

Navigation::init(void)
{
    pinMode(_backLeftIn1, OUTPUT);
    pinMode(_backLeftIn2, OUTPUT);

    pinMode(_backRightIn1, OUTPUT);
    pinMode(_backRightIn2, OUTPUT);

    pinMode(_frontRightIn1, OUTPUT);
    pinMode(_frontRightIn2, OUTPUT);

    pinMode(_frontLeftIn1, OUTPUT);
    pinMode(_frontLeftIn2, OUTPUT);

    if(_usesPWM) 
    {
        pinMode(_pwmBackLeft, OUTPUT);
		pinMode(_pwmBackRight, OUTPUT);
        pinMode(_pwmFrontRight, OUTPUT);
        pinMode(_pwmFrontLeft, OUTPUT);
    }
}

void Navigation::forward(void)
{
    digitalWrite(_backLeftIn1, HIGH);
    digitalWrite(_backLeftIn2, LOW);

    digitalWrite(_backRightIn1, HIGH);
    digitalWrite(_backRightIn2, LOW);

    digitalWrite(_frontRightIn1, HIGH);
    digitalWrite(_frontRightIn2, LOW);

    digitalWrite(_frontLeftIn1, HIGH);
	digitalWrite(_frontLeftIn2, LOW);
}

void Navigation::reverse(void)
{
    digitalWrite(_backLeftIn1, HIGH);
    digitalWrite(_backLeftIn2, LOW);

    digitalWrite(_backRightIn1, HIGH);
    digitalWrite(_backRightIn2, LOW);

    digitalWrite(_frontRightIn1, HIGH);
    digitalWrite(_frontRightIn2, LOW);

    digitalWrite(_frontLeftIn1, HIGH);
	digitalWrite(_frontLeftIn2, LOW);
}


void Navigation::left(void)
{
    digitalWrite(_backLeftIn1, HIGH);
    digitalWrite(_backLeftIn2, LOW);

    digitalWrite(_backRightIn1, HIGH);
    digitalWrite(_backRightIn2, LOW);

    digitalWrite(_frontRightIn1, HIGH);
    digitalWrite(_frontRightIn2, LOW);

    digitalWrite(_frontLeftIn1, HIGH);
	digitalWrite(_frontLeftIn2, LOW);
}

void Navigation::right(void)
{
    digitalWrite(_backLeftIn1, HIGH);
    digitalWrite(_backLeftIn2, LOW);

    digitalWrite(_backRightIn1, HIGH);
    digitalWrite(_backRightIn2, LOW);

    digitalWrite(_frontRightIn1, HIGH);
    digitalWrite(_frontRightIn2, LOW);

    digitalWrite(_frontLeftIn1, HIGH);
	digitalWrite(_frontLeftIn2, LOW);
}

void Navigation::forward(uint8_t speed)
{
    Navigation::forward();
    Navigation::setSpeed(speed);
}

void Navigation::reverse(uint8_t speed)
{
    Navigation::reverse();
    Navigation::setSpeed(speed);
}

void Navigation::left(uint8_t speed)
{
    Navigation::left();
    Navigation::setSpeed(speed);
}

void Navigation::right(uint8_t speed)
{
    Navigation::right();
    Navigation::setSpeed(speed);
}


void Navigation::setSpeed(uint8_t speed) 
{
    analogWrite(_pwmBackLeft, _speed);
    analogWrite(_pwmBackRight, _speed);
    analogWrite(_pwmFrontRight, _speed);
    analogWrite(_pwmFrontLeft, _speed);
}

void Navigation::drive(uint8_t direction)
{
  switch(direction)
  {
    case FORWARD:
      Navigation::forward();
    break;

    case REVERSE:
      Navigation::reverse();
    break;

    case LEFT:
      Navigation::left();
    break;

    case RIGHT:
      Navigation::right();
    break;

    case STOP:
      Navigation::stop();
    break;
  }
}

void Navigation::drive(uint8_t direction, uint8_t speed)
{
  switch(direction)
  {
    case FORWARD:
      Navigation::forward(speed);
    break;

    case REVERSE:
      Navigation::reverse(speed);
    break;

    case LEFT:
      Navigation::left(speed);
    break;

    case RIGHT:
      Navigation::right(speed);
    break;

    case STOP:
      Navigation::stop(speed);
    break;
  }
}