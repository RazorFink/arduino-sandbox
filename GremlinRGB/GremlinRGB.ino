//Use a servo to protect the LDR from light
#include <Servo.h>

int const ldrPin = A0;     //LDR Input Pin
int const servoPin = 9;   //Servo control pin
int const ledPinRed = 6;
int const ledPinGreen = 5;
int const ledPinBlue = 3;
int const servoClose = 40;          //Minimum Servo Rotation
int const servoOpen = 168;        //Maximum Servo Rotation

Servo lidServo;          //Servo Object

int lightADC = 0;          //Holds raw ADC value from LDR
int lightMax = 35;
int lightMin = 15;
//int servoPosition = 0;     //Servo Rotational Position (degrees)

void setup()
{

  lidServo.attach(servoPin);
  lidServo.write(servoClose);
  pinMode(ldrPin, INPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);

  lightMin = getLight() + 10;   //Set Minimum 
}

void loop()
{
  setRGB(255,0,0);
  delay(200);
  setRGB(0,255,0);
  delay(200);
  setRGB(0,0,255);
  delay(200);
  setRGB(0,0,0);
  if (getLight() > lightMax) {
    lidServo.write(servoClose);
    delay(5000);    
  }
  if (getLight() < lightMin) {
    int servoPosition = lidServo.read();
    while (servoPosition < servoOpen && getLight() < lightMax)
    {
      lidServo.write(servoPosition++);
      delay(20);
    }
  }
}

int getLight()
{
  analogRead(ldrPin); 
}

void setRGB(int red, int green, int blue)
{
  setRed(red);
  setGreen(green);
  setBlue(blue);
}

void setRed(int val)
{
  analogWrite(ledPinRed, val);
}

void setGreen(int val)
{
  analogWrite(ledPinGreen, val);
}

void setBlue(int val)
{
  analogWrite(ledPinBlue, val);
}
