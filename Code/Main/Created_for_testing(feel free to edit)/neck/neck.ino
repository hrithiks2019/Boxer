#include <Servo.h>

Servo horizontal;
Servo vertical;

int pos = 0;    

void setup() {
  horizontal.attach(3);
  vertical.attach(6);
  horizontal.write(90);
  vertical.write(90);
  
}

void loop() 
{
  horizontal.write(90);
  vertical.write(90);
 
for (pos = 0; pos >= 180; pos += 1) 
  { 
    horizontal.write(pos);
    vertical.write(pos);
    delay(50);                       
  }
  
  for (pos = 180; pos >= 0; pos -= 1) 
  { 
    horizontal.write(pos);
    vertical.write(pos);
  delay(5a`0);                       
  }
}   
