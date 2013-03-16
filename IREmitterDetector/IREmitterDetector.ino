// IR Emitter and Detector
// Try out some infraredness

void setup(){
  pinMode(9, OUTPUT);  //IR emitter enable
  pinMode(13, OUTPUT); ///built in LED
  digitalWrite(14, HIGH); // enable pullup resistor on analog input A0/D14
  Serial.begin(9600);
}

void loop() {
  int infrared; // how much infrared light detected
  int threshold;  // adjustable comparison value
  
  digitalWrite(9, HIGH); // enable infrared emitter
  threshold = 1023 - analogRead(1); // get threshold value
  infrared = 1023 - analogRead(0); // get voltage from detector circuit
  digitalWrite(9, LOW); // disable infrared emitter
  Serial.print("threshold:");
  Serial.print(threshold);
  Serial.print(", IR:");
  Serial.println(infrared);
  delay(200);
  if(infrared > threshold) {
    digitalWrite(13, HIGH); // LED on = IR above threshold 
  } else {
    digitalWrite(13, LOW); // LED off = IR below threshold 
  }

}
