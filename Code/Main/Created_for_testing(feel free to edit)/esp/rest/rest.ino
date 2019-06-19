#include <Servo.h>

Servo leftThighFront; // bwhite
Servo leftThighback; // red
Servo RightThighfront; //blue
Servo RightThighback;  // rwhite
Servo Lefthindback; //orange
Servo Righthindfront; // owhite
Servo Righthindback; //orange
Servo leftthindfront; // owhite

int pos = 0;    
int pos2 =0;

void setup() 
{
  servosetup();
  stand();
  delay(2000);
  
}

void loop() 
{
 stand();
}


void servosetup()
{
  leftThighFront.attach(D3);
  leftThighback.attach(D6);
  RightThighfront.attach(D4);
  RightThighback.attach(D5);

 
  Lefthindback.attach(D2); 
  Righthindfront.attach(D7); 
  Righthindback.attach(D1); 
  leftthindfront.attach(D8); 

}

void stand()
{
  leftThighFront.write(90);
  leftThighback.write(90);
  RightThighfront.write(100);
  RightThighback.write(100);
  leftthindfront.write(120); // super fix
  Lefthindback.write(90);
  Righthindfront.write(50);
  Righthindback.write(90);
}
