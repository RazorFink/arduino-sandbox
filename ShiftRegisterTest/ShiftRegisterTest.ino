//  Shift Register Test
// 

const int SER = 10;  // serial data
const int RCLK = 9; // serial clock
const int SRCLK = 8;  // register clock

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  digitalWrite(SER, LOW);
  digitalWrite(SRCLK, LOW);
  digitalWrite(RCLK, LOW);
  for (int i = 0; i < 8; i++){
     digitalWrite(SRCLK, HIGH);
     digitalWrite(SER, HIGH);
     digitalWrite(SRCLK, LOW);
  }
  digitalWrite(RCLK, HIGH);
}

void loop() {
  
}

