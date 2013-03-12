// Servo Sweep
#include <Servo.h>

Servo myservo;

int pos = 90;

void setup() 
{
  pinMode(9, OUTPUT);
  myservo.attach(9); 
  myservo.write(pos);
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available())
  {
    pos = Serial.read();
    myservo.write(pos);  
  }
  delay(100);
}
