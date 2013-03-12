// InterruptTest

#define interruptPin 2
#define ledPin 13
int period = 500;

void setup()
{
 pinMode(ledPin, OUTPUT);
pinMode(interruptPin, INPUT);
digitalWrite(interruptPin, HIGH);
attachInterrupt(0, goFast, CHANGE);
}

void loop()
{
  digitalWrite(ledPin, HIGH);
  delay(period); 
  digitalWrite(ledPin, LOW);
  delay(period); 
}

void goFast()
{
  if (period == 500)
  {
    period = 100;  
  }else{
    period = 500; 
  }
}


