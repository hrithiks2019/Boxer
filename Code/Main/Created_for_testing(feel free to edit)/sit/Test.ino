#include <Servo.h>

Servo leftThighFront; 
Servo leftThighback; 
Servo RightThighfront; 
Servo RightThighback;  
Servo Lefthindback; 
Servo Righthindfront; 
Servo Righthindback; 
Servo leftthindfront; 

int pos = 0;    
int pos2 = 0;
int Dword = 0; 

bool sit = false;

void setup() 
{
  Serial.begin(115200);
  delay(10000);
  servosetup();
  delay(100);
  communicate();
  delay(2000);
  test();
  delay(3000);
  hello();
  stand();
  
}

void loop() 
{
   
}


void sit()
{
   for (pos = 90; pos <= 130; pos += 1) 
   { 
      pos2 = 180 - pos;
      leftThighFront.write(pos-10);
      delay(2);
      RightThighfront.write(195-pos);
      delay(2);
      leftThighback.write(pos2+20);
      delay(2);
      RightThighback.write(pos-10);
      delay(2);
      leftthindfront.write(pos);
      delay(2);
      Righthindfront.write(pos2-20);
      delay(2);
      Lefthindback.write(pos+20); 
      delay(2);
      Righthindback.write(pos2-15);     // 180 - 130 = 50 - 15 = 35   
      delay(30);                        
  }
  sit = true;
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
  leftthindfront.write(90);
  Lefthindback.write(90);
  Righthindfront.write(90);
  Righthindback.write(90);
  sit = false;
}

void test()
{
  delay(1000);
  Serial.println("Standing Up");
  stand();
  Serial.println("Standing step complete");
  delay(2000);
  Serial.println("Sitting");
  sit();
  delay(5000);
  shake();
  delay(500);
}

void hello()
{
  if (sit == false)
    {
	    sit();
	}
  
  for (pos = 65; pos<= 180; pos+=1)
      {
        RightThighfront.write(pos);
        delay(10);
      }
  delay(100);
  for (int i =0; i<=3; i+=1)
  {  
		Serial.println("Hello My Human Friend");
		for (pos =0; pos <=120; pos+=1)
			{
				Righthindfront.write(pos); 
				delay(5); 
			}
		for (pos = 120; pos <=0; pos-=1)
			{
				Righthindfront.write(pos); 
				delay(5); 
			}    
  }
  for (pos = 180; pos<= 65; pos -= 1)
      {
        pos2 = 180 - pos;
		RightThighfront.write(pos);
        Righthindfront.write(pos2 - 80); // 180 - 65 = 115 
		delay(10);
		
      }
  
}

void communicate()
{
  
  Serial.println("Boxer 1.0 Systems Intiating.......");
  delay(100);
  Serial.println("Checking Core Systems ..... OK");
  delay(100);
  Serial.println("Checking Servo control Systems ..... OK");
  delay(100);
  Serial.println(" Connection Established ..... OK");
  delay(100);
  Serial.println("Core System Initiating  ..... OK");
  delay(100);
  Serial.println("Servo Setup Intiating ......");
  delay(100);
  Serial.println("Servo Setup Complete (*~*) ... ");
}