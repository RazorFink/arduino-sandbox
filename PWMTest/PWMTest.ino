// PWM Test

#define outputPin 13

void setup()
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter Volts 0 to 5"); 
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    int volts = (ch - '0') * 51;
    Serial.println(volts);
    analogWrite(outputPin, volts);
  }
}
