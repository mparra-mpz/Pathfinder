/*
 * Author: Manuel Parra Z.
 * Date: 14/11/2015
 * License: MIT License
 * Materials:
 *      - Arduino Uno R3
 *      - DFRobot DF-MD V1.3
 *      - DFRobot Pirate 4WD
 * Description: This sketch will use as a movements tests, first the rover
 * will go foward on the track, then it will go on reverse, then will turn
 * to left and then will turn to right finally the rover will be stop during
 * 3 seconds. This sketch will show if you connected the engines and batteries
 * properly. Don't forget to review the fritzing electronic diagram in the
 * document section of the project.
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
  rover.setSpeed(200);
  
  Serial.println("Foward for 3 seconds.");
  rover.foward();
  Serial.print("Rover direction: ");
  Serial.println(rover.getDirection());
  delay(3000);
  
  Serial.println("Reverse for 3 seconds.");
  rover.reverse();
  Serial.print("Rover direction: ");
  Serial.println(rover.getDirection());
  delay(3000);
  
  Serial.println("Left for 3 seconds.");
  rover.left();
  Serial.print("Rover direction: ");
  Serial.println(rover.getDirection());
  delay(3000);
  
  Serial.println("Right for 3 seconds.");
  rover.right();
  Serial.print("Rover direction: ");
  Serial.println(rover.getDirection());
  delay(3000);
  
  Serial.println("Stop for 3 seconds.");
  rover.stop();
  Serial.print("Rover direction: ");
  Serial.println(rover.getDirection());
  delay(3000);
}
