#include <Servo.h>

Servo leftfront; // bwhite
Servo leftback; // red
Servo rightfront; //blue
Servo rightback;  // rwhite
 
int pos = 0;    
int pos2 =0;
void setup() {
  leftfront.attach(11);
  leftback.attach(5);
  rightfront.attach(9);
  rightback.attach(6);
  leftfront.write(90);
  leftback.write(90);
  rightfront.write(86);
  rightback.write(87);
  Serial.begin(115200); 
}

void loop() {
  for (pos = 55; pos <= 90; pos += 1) { 
    leftfront.write(pos2);
  pos2 = 150-pos;
  leftback.write(pos2);
  rightfront.write(pos);
  rightback.write(pos);
  Serial.print("angle is");
  Serial.println(pos);
    
    delay(15);                       
  }
  for (pos = 90; pos >= 55; pos -= 1) { // goes from 180 degrees to 0 degrees
    leftfront.write(pos2);
    pos2 = 150-pos;
    leftback.write(pos2);
    rightfront.write(pos);
    rightback.write(pos);
  Serial.print("angle is");
  Serial.println(pos);
  
    delay(15);                       
    
  }
}
