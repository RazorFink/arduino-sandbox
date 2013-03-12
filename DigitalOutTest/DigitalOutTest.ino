#define outPin 4

void setup()
{
  pinMode(outPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter 1 or 0");
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == '1')
    {
      digitalWrite(outPin, HIGH);  
    }
    else if (ch == '0')
    {
      digitalWrite(outPin, LOW);
    }
  }
}
