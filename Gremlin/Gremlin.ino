//Use a servo to protect the LDR from light
#include <Servo.h>

int const ldrPin = A0;     //LDR Input Pin
int const servoPin = 9;   //Servo control pin
int const ledPin = 4;
int const blinkDelay = 50;
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
  pinMode(ledPin, OUTPUT);
  eyesOn();
  delay(20);
  lightMin = getLight() + 10;   //Set Minimum 
  eyesOff();
}

void loop()
{
  if (getLight() > lightMax) {
    eyesOff();
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
    eyesOn();
  }
}

int getLight()
{
  analogRead(ldrPin); 
}

void eyesOn()
{
  digitalWrite(ledPin, HIGH); 
}

void eyesOff()
{
  digitalWrite(ledPin, LOW);  
}

void eyesBlink(int blinks)
{
  for (int i; i < blinks; i++) { 
    eyesOff();
    delay(blinkDelay); 
    eyesOn();
    delay(blinkDelay);
  }
}

