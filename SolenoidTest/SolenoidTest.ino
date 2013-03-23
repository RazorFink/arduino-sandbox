//  Solenoid Test
// Driving a 5v Solenoid with a ULN2803 Darlington IC
// Drive Pin 3 high to activate solenoid

const int solenoidPin = 3;
const int potPin = A0;

void setup() {
  //bitSet(DDRD, 3);  //DDR Pord D, Pin 3 OUTPUT
  pinMode(solenoidPin, OUTPUT);
  pinMode(potPin, INPUT);
  digitalWrite(solenoidPin, LOW);
}

void loop() {
  digitalWrite(solenoidPin, HIGH);
  delay(potVal());
  digitalWrite(solenoidPin, LOW);
  delay(potVal());
}

int potVal() {
  return analogRead(potPin);
}
