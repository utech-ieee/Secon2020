#ifndef __HOLONOMIC_NAVIGATION_H__
#define __HOLONOMIC_NAVIGATION_H__


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
#define SPIN_LEFT 6
#define SPIN_RIGHT 7
#define DIAGONAL_FORWARD_LEFT 8
#define DIAGONAL_FORWARD_RIGHT 9
#define DIAGONAL_REVERSE_LEFT 10
#define DIAGONAL_REVERSE_RIGHT 11

class HolonomicNavigation 
{
  public:
    HolonomicNavigation() {}
    ~HolonomicNavigation() {}

    virtual void init()=0;
    virtual void drive(uint8_t direction)=0;
    virtual void drive(uint8_t direction, uint8_t speed)=0;

    virtual void forward()=0;
    virtual void reverse()=0;
    virtual void left()=0;
    virtual void right()=0;
    virtual void stop()=0;
    virtual void spinLeft()=0;
    virtual void spinRight()=0;
    virtual void diagonalForwardLeft()=0;
    virtual void diagonalForwardRight()=0;
    virtual void diagonalReverseLeft()=0;
    virtual void diagonalReverseRight()=0;
    virtual void forward(uint8_t speed)=0;
    virtual void reverse(uint8_t speed)=0;
    virtual void left(uint8_t speed)=0;
    virtual void right(uint8_t speed)=0;
    virtual void spinLeft(uint8_t speed)=0;
    virtual void spinRight(uint8_t speed)=0;
    virtual void diagonalForwardLeft(uint8_t speed)=0;
    virtual void diagonalForwardRight(uint8_t speed)=0;
    virtual void diagonalReverseLeft(uint8_t speed)=0;
    virtual void diagonalReverseRight(uint8_t speed)=0;
    virtual void setSpeed(uint8_t speed)=0;
};

class FourWheelNavigation: public HolonomicNavigation
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

  void forward() override;
  void reverse() override;
  void left() override;
  void right() override;
  void stop() override;
  void spinLeft() override;
  void spinRight() override;
  void diagonalForwardLeft() override;
  void diagonalForwardRight() override;
  void diagonalReverseLeft() override;
  void diagonalReverseRight() override;
  void forward(uint8_t speed) override;
  void reverse(uint8_t speed) override;
  void left(uint8_t speed) override;
  void right(uint8_t speed) override;
  void spinLeft(uint8_t speed) override;
  void spinRight(uint8_t speed) override;
  void diagonalForwardLeft(uint8_t speed) override;
  void diagonalForwardRight(uint8_t speed) override;
  void diagonalReverseLeft(uint8_t speed) override;
  void diagonalReverseRight(uint8_t speed) override;

  void setSpeed(uint8_t speed) override;

public:
  FourWheelNavigation(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t backRightIn1, uint8_t backRightIn2);
  FourWheelNavigation(uint8_t frontLeftIn1, uint8_t frontLeftIn2, uint8_t pwmFrontLeft, uint8_t frontRightIn1, uint8_t frontRightIn2, uint8_t pwmFrontRight, uint8_t backLeftIn1, uint8_t backLeftIn2, uint8_t pwmBackLeft, uint8_t backRightIn1, uint8_t backRightIn2, uint8_t pwmBackRight);
  ~FourWheelNavigation();
  void init();
  void drive(uint8_t direction);
  void drive(uint8_t direction, uint8_t speed);
};

#endif
