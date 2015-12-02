/*
 * Author: Manuel Parra Z.
 * Date: 30/11/2015
 * License: MIT License
 * Materials:
 *      - Arduino Uno R3
 *      - DFRobot DF-MD V1.3
 *      - DFRobot Pirate 4WD
 *      - Reflective Object Sensor QRD1114
 * Description: This sketch give to the rover the
 * ability to follow the path mark by a black
 * line in the floor.
 * Link: https://github.com/mparra-mpz/Pathfinder
 */
 
#include <Pirate4WD.h>
#include <QRD1114.h>

/* Pin 4 is use to control the direction in the
 * left motors. Pin 5 is use to control the power
 * in the left motors. Pin 6 is use to control
 * the power in the right motors. Pin 7 is use to
 * control the direction in the right motors.
 */
Pirate4WD rover = Pirate4WD(4,5,7,6);
/*
 * Right sensor is connect to A0, left sensor
 * is connect to A1 and use a tolerance of 10%.
 * The tolerance will help us to define when the
 * sensor is out of the expected margin.
 */ 
QRD1114 detector = QRD1114(A0,A1,10);

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting rover setup");
  detector.calibrateSensors();
  Serial.println("Finish rover setup");
}

void loop()
{
  // Read the sensors and set the direction.
  detector.readSensors();
  Direction value = detector.getDirection();
  rover.setSpeed(250);
  if (value == FOWARD)
  {
    Serial.println("FOWARD");
    rover.foward();
  }
  else if (value == LEFT)
  {
    Serial.println("LEFT");
    rover.left();
  }
  else if (value == RIGHT)
  {
    Serial.println("RIGHT");
    rover.right();
  } else if (value == STOP)
  {
    Serial.println("STOP");
    rover.stop();
  }
}
