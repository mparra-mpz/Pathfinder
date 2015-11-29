/*
 * Author: Manuel Parra Z.
 * Date: 18/11/2015
 * License: MIT License
 * Materials:
 *      - Arduino Uno R3
 *      - DFRobot DF-MD V1.3
 *      - DFRobot Pirate 4WD
 * Description: This library will control the rover
 * movements with the materials previously described.
 * Review the Fritzing electronic diagram in the doc
 * section.
 * Link: https://github.com/mparra-mpz/Pathfinder
 */

#include "Arduino.h"
#include "Pirate4WD.h"

Pirate4WD::Pirate4WD(int _M1, int _E1, int _M2, int _E2)
{
  M1 = _M1;
  E1 = _E1;
  M2 = _M2;
  E2 = _E2;
  speed = 0;
  direction = STOP;
  pinMode(M1, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E2, OUTPUT);
}

void Pirate4WD::foward()
{
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  direction = FOWARD;
}

void Pirate4WD::reverse()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  direction = REVERSE;
}

void Pirate4WD::left()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  direction = LEFT;
}

void Pirate4WD::right()
{
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  direction = RIGHT;
}

void Pirate4WD::stop()
{
  speed = 0;
  direction = STOP;
  analogWrite(E1, speed);
  analogWrite(E2, speed);
}

int Pirate4WD::getSpeed()
{
  return speed;
}

void Pirate4WD::setSpeed(int _speed)
{
  if (_speed >= 0 && _speed <= 255)
  {
    speed = _speed;
    analogWrite(E1, speed);
    analogWrite(E2, speed);
  }
}

Direction Pirate4WD::getDirection()
{
  return direction;
}
