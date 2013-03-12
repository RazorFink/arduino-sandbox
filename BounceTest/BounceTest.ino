//bounce test
#include <Bounce.h>

#define inputPin 5
#define ledPin   13
int ledValue = LOW;

Bounce bouncer = Bounce(inputPin, 5);

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin, HIGH); 
}

void loop()
{
  if (bouncer.update() && !bouncer.read())
  {
    ledValue = ! ledValue;
    digitalWrite(ledPin, ledValue);
  }
}
