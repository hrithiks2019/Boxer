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
int pos2 = 0;
int Dword = 0; 


void setup() 
{
  Serial.begin(115200);
  delay(10000);
  Serial.println("Servo Setup Intiating ......");
  servosetup();
  delay(100);
  Serial.println("Servo Setup Complete (*~*) ... ");
  
}

void loop() 
{
  
  Dword = Serial.read();
  if(Dword == '1')
  {
    test();
  }
 if(Dword == '2')
  {
    shake();
  }
  
}


void sit()
{
      leftThighFront.write(120); // 130-10 = 120
      delay(2);
      RightThighfront.write(180); // 195-130 = 65
      delay(2); 
      leftThighback.write(70); // 180-130 = 50 + 20 = 70 
      delay(2);
      RightThighback.write(120); // 130 - 10  = 120 
      delay(2);
      leftthindfront.write(130);  // 130
      delay(2);
      Righthindfront.write(30); // 50 -20 = 30
      delay(2);
      Lefthindback.write(150); // 130 + 20 = 150
      delay(2);
      Righthindback.write(35); //50 - 15 = 35
      delay(5000);       
      
  
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



void test()
{
 sit(); 
}

void shake()
{
  while (true)
  {  
		for (pos = 65; pos<= 180; pos+=1)
			{
				RightThighfront.write(pos);
				delay(5);
			}
		delay(100);
		for (pos =0; pos <=120; pos+=1)
			{
				Righthindfront.write(pos); // 50 -20 = 30
				delay(5); 
			}
		for (pos = 120; pos <=0; pos-=1)
			{
				Righthindfront.write(pos); // 50 -20 = 30
				delay(5); 
			}    
  }
}
