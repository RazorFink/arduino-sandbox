// 8 bit Binary Counter

int const ledPin[] = {2,3,4,5,6,7,8,9};
int const ledCount = 8;
int const sensorPin = A5;
int const timer = 100;
//int const countMax = 255;
//int count = 0;

void setup() { 
  //Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPin[i], OUTPUT) ;
  }  
  clearDisplay();
}

void loop() {
  int light = map(analogRead(sensorPin), 0, 1023, 0, 255);
  //Serial.println(light);
  binDisplay(light);
  delay(timer);
  clearDisplay();
}

void clearDisplay(){
  for (int i = 0; i < ledCount; i++){
    digitalWrite(ledPin[i], LOW); 
  }
}

void binDisplay(int value){
  //start with most significant bit
  int currentLed = ledCount-1;
  while (value > 0) {
    digitalWrite(ledPin[currentLed], value%2);
    value>>=1; //divide value in half, bit shift right  
    currentLed--; //decrement currentLed
  }
}
