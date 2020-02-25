#include "HolonomicNavigation.h"


/****************************************************
 *             FOUR WHEEL NAVIGATION                *
 * **************************************************/

FourWheelNavigation::FourWheelNavigation(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t backRightIn1, uint8_t backRightIn2) : _frontLeftIn1(frontLeftIn1), _frontLeftIn2(frontLeftIn2), _frontRightIn1(frontRightIn1), _frontRightIn2(frontRightIn2), _backLeftIn1(backLeftIn1), _backLeftIn2(backLeftIn2), _backRightIn1(backRightIn1), _backRightIn2(backRightIn2)
{
  _usesPWM = false;
}

FourWheelNavigation::FourWheelNavigation(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t pwmFrontLeft, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t pwmFrontRight, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t pwmBackLeft, uint8_t backRightIn1, uint8_t backRightIn2, uint8_t pwmBackRight) : _frontLeftIn1(frontLeftIn1), _frontLeftIn2(frontLeftIn2),  _pwmFrontLeft(pwmFrontLeft), _frontRightIn1(frontRightIn1), _frontRightIn2(frontRightIn2), _pwmFrontRight(pwmFrontRight),_backLeftIn1(backLeftIn1), _backLeftIn2(backLeftIn2), _pwmBackLeft(pwmBackLeft), _backRightIn1(backRightIn1), _backRightIn2(backRightIn2), _pwmBackRight(pwmBackRight)
{
  _usesPWM = true;
}

FourWheelNavigation::~FourWheelNavigation() {}

void FourWheelNavigation::init()
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

void FourWheelNavigation::forward()
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

void FourWheelNavigation::reverse()
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


void FourWheelNavigation::left()
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

void FourWheelNavigation::right()
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

void FourWheelNavigation::spinLeft()
{
  digitalWrite(_backLeftIn1, LOW);
  digitalWrite(_backLeftIn2, LOW);

  digitalWrite(_backRightIn1, LOW);
  digitalWrite(_backRightIn2, LOW);

  digitalWrite(_frontRightIn1, LOW);
  digitalWrite(_frontRightIn2, LOW);

  digitalWrite(_frontLeftIn1, LOW);
	digitalWrite(_frontLeftIn2, LOW);
}

void FourWheelNavigation::spinRight()
{
  digitalWrite(_backLeftIn1, LOW);
  digitalWrite(_backLeftIn2, LOW);

  digitalWrite(_backRightIn1, LOW);
  digitalWrite(_backRightIn2, LOW);

  digitalWrite(_frontRightIn1, LOW);
  digitalWrite(_frontRightIn2, LOW);

  digitalWrite(_frontLeftIn1, LOW);
	digitalWrite(_frontLeftIn2, LOW);
}

void FourWheelNavigation::diagonalForwardLeft()
{
  digitalWrite(_backLeftIn1, LOW);
  digitalWrite(_backLeftIn2, LOW);

  digitalWrite(_backRightIn1, LOW);
  digitalWrite(_backRightIn2, LOW);

  digitalWrite(_frontRightIn1, LOW);
  digitalWrite(_frontRightIn2, LOW);

  digitalWrite(_frontLeftIn1, LOW);
	digitalWrite(_frontLeftIn2, LOW);
}

void FourWheelNavigation::diagonalForwardRight()
{
  digitalWrite(_backLeftIn1, LOW);
  digitalWrite(_backLeftIn2, LOW);

  digitalWrite(_backRightIn1, LOW);
  digitalWrite(_backRightIn2, LOW);

  digitalWrite(_frontRightIn1, LOW);
  digitalWrite(_frontRightIn2, LOW);

  digitalWrite(_frontLeftIn1, LOW);
	digitalWrite(_frontLeftIn2, LOW);
}

void FourWheelNavigation::diagonalReverseLeft()
{
  digitalWrite(_backLeftIn1, LOW);
  digitalWrite(_backLeftIn2, LOW);

  digitalWrite(_backRightIn1, LOW);
  digitalWrite(_backRightIn2, LOW);

  digitalWrite(_frontRightIn1, LOW);
  digitalWrite(_frontRightIn2, LOW);

  digitalWrite(_frontLeftIn1, LOW);
	digitalWrite(_frontLeftIn2, LOW);
}

void FourWheelNavigation::diagonalReverseRight()
{
  digitalWrite(_backLeftIn1, LOW);
  digitalWrite(_backLeftIn2, LOW);

  digitalWrite(_backRightIn1, LOW);
  digitalWrite(_backRightIn2, LOW);

  digitalWrite(_frontRightIn1, LOW);
  digitalWrite(_frontRightIn2, LOW);

  digitalWrite(_frontLeftIn1, LOW);
	digitalWrite(_frontLeftIn2, LOW);
}

void FourWheelNavigation::stop()
{
  digitalWrite(_backLeftIn1, LOW);
  digitalWrite(_backLeftIn2, LOW);

  digitalWrite(_backRightIn1, LOW);
  digitalWrite(_backRightIn2, LOW);

  digitalWrite(_frontRightIn1, LOW);
  digitalWrite(_frontRightIn2, LOW);

  digitalWrite(_frontLeftIn1, LOW);
	digitalWrite(_frontLeftIn2, LOW);
  // FourWheelNavigation::setSpeed(0);
}

void FourWheelNavigation::forward(uint8_t speed)
{
  FourWheelNavigation::forward();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::reverse(uint8_t speed)
{
  FourWheelNavigation::reverse();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::left(uint8_t speed)
{
  FourWheelNavigation::left();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::right(uint8_t speed)
{
  FourWheelNavigation::right();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::spinLeft(uint8_t speed)
{
  FourWheelNavigation::spinLeft();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::spinRight(uint8_t speed)
{
  FourWheelNavigation::spinRight();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::diagonalForwardLeft(uint8_t speed)
{
  FourWheelNavigation::diagonalForwardLeft();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::diagonalForwardRight(uint8_t speed)
{
  FourWheelNavigation::diagonalForwardRight();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::diagonalReverseLeft(uint8_t speed)
{
  FourWheelNavigation::diagonalReverseLeft();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::diagonalReverseRight(uint8_t speed)
{
  FourWheelNavigation::diagonalReverseRight();
  FourWheelNavigation::setSpeed(speed);
}

void FourWheelNavigation::setSpeed(uint8_t speed) 
{
  analogWrite(_pwmBackLeft, _speed);
  analogWrite(_pwmBackRight, _speed);
  analogWrite(_pwmFrontRight, _speed);
  analogWrite(_pwmFrontLeft, _speed);
}

void FourWheelNavigation::drive(uint8_t direction)
{
  switch(direction)
  {
    case FORWARD:
      FourWheelNavigation::forward();
    break;

    case REVERSE:
      FourWheelNavigation::reverse();
    break;

    case LEFT:
      FourWheelNavigation::left();
    break;

    case RIGHT:
      FourWheelNavigation::right();
    break;

    case STOP:
      FourWheelNavigation::stop();
    break;

    case SPIN_LEFT:
      FourWheelNavigation::spinLeft();
    break;

    case SPIN_RIGHT:
      FourWheelNavigation::spinRight();
    break;

    case DIAGONAL_FORWARD_LEFT:
      FourWheelNavigation::diagonalForwardLeft();
    break;

    case DIAGONAL_FORWARD_RIGHT:
      FourWheelNavigation::diagonalForwardLeft();
    break;

    case DIAGONAL_REVERSE_LEFT:
      FourWheelNavigation::diagonalReverseLeft();
    break;

    case DIAGONAL_REVERSE_RIGHT:
      FourWheelNavigation::diagonalReverseRight();
    break;
  }
}

void FourWheelNavigation::drive(uint8_t direction, uint8_t speed)
{
  switch(direction)
  {
    case FORWARD:
      FourWheelNavigation::forward(speed);
    break;

    case REVERSE:
      FourWheelNavigation::reverse(speed);
    break;

    case LEFT:
      FourWheelNavigation::left(speed);
    break;

    case RIGHT:
      FourWheelNavigation::right(speed);
    break;

    case STOP:
      FourWheelNavigation::stop();
    break;

    case DIAGONAL_FORWARD_LEFT:
      FourWheelNavigation::diagonalForwardLeft(speed);
    break;

    case DIAGONAL_FORWARD_RIGHT:
      FourWheelNavigation::diagonalForwardLeft(speed);
    break;

    case DIAGONAL_REVERSE_LEFT:
      FourWheelNavigation::diagonalReverseLeft(speed);
    break;

    case DIAGONAL_REVERSE_RIGHT:
      FourWheelNavigation::diagonalReverseRight(speed);
    break;
  }
}