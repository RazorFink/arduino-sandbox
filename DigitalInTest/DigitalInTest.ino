#define inPin 5

void setup()
{
  pinMode(inPin, INPUT);
  digitalWrite(inPin, HIGH);  //pullup resistor
  Serial.begin(9600); 
}

void loop()
{
  Serial.println(digitalRead(inPin));
  delay(100); 
}
