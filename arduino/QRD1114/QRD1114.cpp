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

#include "Arduino.h"
#include "QRD1114.h"

QRD1114::QRD1114(int _rightSensorPin, int _leftSensorPin, int _tolerance)
{
  rightSensorPin = _rightSensorPin;
  leftSensorPin = _leftSensorPin;
  rightSensor = 0;
  leftSensor = 0;
  tolerance = float(_tolerance) / 100;
  direction = STOP;
}

void QRD1114::calibrateSensor()
{
  long temporalRightSensor = 0;
  long temporalLeftSensor = 0;
  delay(1000);
  for (int i = 0; i < 100; i++)
  {
    temporalRightSensor = temporalRightSensor + analogRead(rightSensorPin);
    temporalLeftSensor = temporalLeftSensor + analogRead(leftSensorPin);
    delay(10);
  }
  rightSensor = int(temporalRightSensor / 100);
  rightSensor = int(tolerance * rightSensor) + rightSensor;
  leftSensor = int(temporalLeftSensor / 100);
  leftSensor = int(tolerance * leftSensor) + leftSensor;
}

Direction QRD1114::getDirection()
{
  int temporalRightSensor = 0;
  int temporalLeftSensor = 0;
  temporalRightSensor = analogRead(rightSensorPin);
  temporalLeftSensor = analogRead(leftSensorPin);
  if (temporalRightSensor > rightSensor && temporalLeftSensor < leftSensor)
  {
    direction = RIGHT;
  } else if (temporalRightSensor < rightSensor && temporalLeftSensor > leftSensor)
  {
    direction = LEFT;
  } else if (temporalRightSensor > rightSensor && temporalLeftSensor > leftSensor)
  {
    direction = STOP;
  } else
  {
    direction = FOWARD;
  }
  return direction;
}
