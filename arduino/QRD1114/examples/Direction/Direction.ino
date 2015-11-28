/*
 * Author: Manuel Parra Z.
 * Date: 28/11/2015
 * License: MIT License
 * Materials:
 *      - Arduino Uno R3
 *      - Reflective Object Sensor QRD1114
 * Description: This sketch will use to detect a
 * a black line and decide which direction we
 * must follow.
 * Link: https://github.com/mparra-mpz/Pathfinder
 */
 
#include <QRD1114.h> 

/*
 * Right sensor connected to A0, left sensor
 * connected to A1 and use a tolerance of 10%.
 * The tolerance will help us to define when the
 * sensor is out of the expected margin.
 */ 
QRD1114 detector = QRD1114(A0,A1,10);

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting sensors calibration");
  detector.calibrateSensor();
  Serial.println("Finish sensors calibration");
}

void loop()
{
  Direction value = detector.getDirection();
  if (value == FOWARD)
  {
    Serial.println("FOWARD");
  }
  else if (value == LEFT)
  {
    Serial.println("LEFT");
  }
  else if (value == RIGHT)
  {
    Serial.println("RIGHT");
  } else if (value == STOP)
  {
    Serial.println("STOP");
  } else
  {
    Serial.println("NONE");
  }
  delay(500);
}
