// Sensor Calibration
const int numReadings = 10;
const int sensorPin = A0;
const int ledPin = 3;

int readings[numReadings];
int index = 0;
int total = 0;
int average = 0;

int sensorValue = 0;
int sensorMin = 1023;
int sensorMax = 0;

void setup() 
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  while (millis() < 5000) 
  {
    sensorValue = analogRead(sensorPin); 
    if (sensorValue > sensorMax) 
    {
      sensorMin = sensorValue;
    }
    
    if (sensorValue < sensorMin) 
    {
      sensorMin = sensorValue;
    }
  }
  
  digitalWrite(13, LOW);
  Serial.begin(9600);
  Serial.print("Min: ");
  Serial.println(sensorMin);
  Serial.print("Max: ");
  Serial.println(sensorMax);
  
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  sensorValue = constrain(sensorValue, 0, 255);
  //Serial.println(sensorValue);
  total -= readings[index];
  readings[index] = sensorValue;
  total += readings[index];
  index++;
  if (index >= numReadings)
    index = 0;
  average = total / numReadings;
  analogWrite(ledPin, average);
  delay(1);
}
