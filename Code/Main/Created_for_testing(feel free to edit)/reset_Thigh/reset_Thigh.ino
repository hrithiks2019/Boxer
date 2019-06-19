#include <Servo.h>

Servo leftfront; // bwhite
Servo leftback; // red
Servo rightfront; //blue
Servo rightback;  // rwhite

int pos = 90;    

void setup() {
  leftfront.attach(11);
  leftback.attach(5);
  rightfront.attach(9);
  rightback.attach(6);
  leftfront.write(90);
  leftback.write(90);
  rightfront.write(86);
  rightback.write(87);
}

void loop() 
{
  
  leftfront.write(90);
  leftback.write(90);
  rightfront.write(100);
  rightback.write(100); //87
   
  
}
