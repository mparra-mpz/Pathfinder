/*
 * Author: Manuel Parra Z.
 * Date: 18/11/2015
 * License: MIT License
 * Materials:
 *      - Arduino Uno R3
 *      - DFRobot DF-MD V1.3
 *      - DFRobot Pirate 4WD
 * Description: This sketch will use as a movement test, first the rover
 * will go foward on the track, then it will go reverse, then will turn
 * to left and finally will turn to right. This sketch will show you the
 * if you connected the engines and batteries properly. Don't forget to
 * review the fritzing electronic diagram in the document section of the
 * project.
 * Link: https://github.com/mparra-mpz/Pathfinder
 */

#ifndef Pirate4WD_h
#define Pirate4WD_h

#include "Arduino.h"

enum Direction {STOP, FOWARD, REVERSE, LEFT, RIGHT};

class Pirate4WD
{
  public:
    Pirate4WD(int _M1, int _E1, int _M2, int _E2);
    void foward();
    void reverse();
    void left();
    void right();
    void stop();
    int getSpeed();
    void setSpeed(int _speed);
    Direction getDirection();

  private:
    int M1;
    int E1;
    int M2;
    int E2;
    int speed;
    Direction direction;
};

#endif
