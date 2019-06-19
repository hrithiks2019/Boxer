#include <Servo.h>

Servo leftfront;
Servo leftback;
Servo rightfront;
Servo rightback;  

int pos = 90;    

void setup() {
  leftfront.attach(D3);
  leftback.attach(D6);
  rightfront.attach(D4);
  rightback.attach(D5);
  Serial.begin(115200);
  leftfront.write(90);
  leftback.write(90);
  rightfront.write(86);
  rightback.write(87);

  

}

void loop() {
  for (pos = 50; pos <= 90; pos += 1) { 
    int pos2 = 90 - pos; 
    leftfront.write(pos);
    Serial.println("leftfront Position is :");
    Serial.print(pos);
    rightback.write(pos2);
    Serial.println("rightback Position is :");
    Serial.print(pos2);
    delay(5);                       
  }

  delay(1000);
  for (pos = 90; pos >= 50; pos -= 1) 
  { 
     int pos2 = 90 - pos;  
     rightfront.write(pos);
     Serial.println("righttfront Position is :");
     Serial.print(pos);
     leftback.write(pos2);
     Serial.println("leftback Position is :");
     Serial.print(pos2);
     delay(5);                       
  }
}
