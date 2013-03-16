// IR Emitter and Detector
// Try out some infraredness

void setup(){
  pinMode(13, OUTPUT); ///built in LED
  //digitalWrite(14, HIGH); // enable pullup resistor on analog input A0/D14
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(0));
  delay(100);
}
