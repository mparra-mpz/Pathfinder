/*
 * Author: Manuel Parra Z.
 * Date: 14/11/2015
 * License: MIT License
 * Materials:
 *      - Arduino Uno R3
 *      - DFRobot DF-MD V1.3
 *      - DFRobot Pirate 4WD
 * Description: This sketch will use as a speed test, the
 * analog value will be increase from 0 to 255 or from
 * 0 to 7,5 Volts, this will tell us how much power we
 * need to move the rover.
 * Link: https://github.com/mparra-mpz/Pathfinder
 */
 
#include <Pirate4WD.h>

Pirate4WD rover = Pirate4WD(4,5,7,6);

void setup()
{
  Serial.begin(9600);
  Serial.println("Setup finished.");
}

void loop()
{
  rover.foward();
  for (int i = 0; i <= 255; i += 10)
  {
    rover.setSpeed(i);
    Serial.print("Power is: ");
    Serial.println(rover.getSpeed());
    delay(1000);
  }
}
