#include <ESP8266WiFi.h>


const int LED_PIN = 5; 
const int ANALOG_PIN = A0; 
const int DIGITAL_PIN = 12; 


WiFiServer server(80);

void setup() 
{
  initHardware();
  setupWiFi();
  server.begin();
}

void loop() 
{
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  int val = -1;  

  if (req.indexOf("/led/0") != -1)
    val = 0; 
  else if (req.indexOf("/led/1") != -1)
    val = 1; 
  else if (req.indexOf("/read") != -1)
    val = -2; 

  if (val >= 0)
    digitalWrite(LED_PIN, val);

  client.flush();

  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";
  s += "<meta http-equiv='refresh' content='1'/>\r\n";

  if (val >= 0)
  {
    s += "LED is now ";
    s += (val)?"on":"off";
  }
  else if (val == -2)
  { 
    s += "Analog Pin = ";
    s += String(analogRead(ANALOG_PIN));
    s += "<br>"; 
    s += "Digital Pin 12 = ";
    s += String(digitalRead(DIGITAL_PIN));
  }
  else
  {
    s += "Invalid Request.<br> Try /led/1, /led/0, or /read.";
  }
  s += "</html>\n";

  client.print(s);
  delay(1);

}

void setupWiFi()
{
  WiFi.mode(WIFI_AP);
  WiFi.softAP('project_pegasus', 'password');
}

void startup()
{
  Serial.begin(9600);
  pinMode(D5,OUTPUT); 
  pinMode(D6,OUTPUT); 
  pinMode(D7,OUTPUT); 
  pinMode(D8,OUTPUT); 
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  digitalWrite(D8, LOW);
}


int reading()
{
    int Sum = 0;
    for (int i = 0; i < 50;i++)
    {
        int ginval = analogRead(A0);
        Sum = Sum + ginval;
        int average = (Sum / 50);
    }
    return average
}

void getin()
{
    digitalWrite(D5, LOW);
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
    digitalWrite(D8, HIGH);
}

void getex()
{
    digitalWrite(D5, HIGH);
    digitalWrite(D6, LOW);
    digitalWrite(D7, HIGH);
    digitalWrite(D8, HIGH);
}

void getldr()
{
    digitalWrite(D5, HIGH);
    digitalWrite(D6, HIGH);
    digitalWrite(D7, LOW);
    digitalWrite(D8, HIGH);
}

void checksystem()
{
    if reading() >= 110
    {
        digitalWrite(D8,HIGH);
    }
    else 
    {
        digitalWrite(D8,LOW);
    }
}

void checksystem()
{
    if reading() >= 250
    {
        digitalWrite(D8,HIGH);
    }
    else 
    {
        digitalWrite(D8,LOW);
    }
}
