/*
 * Author: Manuel Parra Z.
 * Date: 14/11/2015
 * License: MIT License
 * Materials:
 *      - Arduino Uno R3
 *      - DFRobot DF-MD V1.3
 *      - DFRobot Pirate 4WD
 * Description:
 *  This sketch will use as a movement test, first the rover will go foward
 * on the track, then it will go reverse, then will turn to left and finally
 * will turn to right. This sketch will show you the if you connected the
 * engines and batteries properly. Don't forget to review the fritzing
 * electronic diagram in the document section of the project
 */
 
 
int M1 = 4;
int E1 = 5;
int E2 = 6;
int M2 = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E2, OUTPUT);
  Serial.println("Setup finished.");
}

void loop()
{
  Serial.println("Foward for 3 seconds.");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 200);
  analogWrite(E2, 200);
  delay(3000);
  
  Serial.println("Reverse for 3 seconds.");
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, 200);
  analogWrite(E2, 200);
  delay(3000);
  
  Serial.println("Left for 3 seconds.");
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 200);
  analogWrite(E2, 200);
  delay(3000);
  
  Serial.println("Right for 3 seconds.");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(E1, 200);
  analogWrite(E2, 200);
  delay(3000);
}
