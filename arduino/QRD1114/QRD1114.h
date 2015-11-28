/*
 * Author: Manuel Parra Z.
 * Date: 27/11/2015
 * License: MIT License
 * Materials:
 *      - Arduino Uno R3
 *      - Reflective Object Sensor QRD1114
 * Description: This library will detect a black line 
 * and it will decide which direction the rover will
 * take using the materials previously described.
 * Link: https://github.com/mparra-mpz/Pathfinder
 */

#ifndef QRD1114_h
#define QRD1114_h

#include "Arduino.h"

enum Direction {STOP, FOWARD, REVERSE, LEFT, RIGHT};

class QRD1114
{
  public:
    QRD1114(int _rightSensorPin, int _leftSensorPin, int _tolerance);
    void calibrateSensor();
    Direction getDirection();

  private:
    int rightSensorPin;
    int leftSensorPin;
    int rightSensor;
    int leftSensor;
    float tolerance;
    Direction direction;
};

#endif
