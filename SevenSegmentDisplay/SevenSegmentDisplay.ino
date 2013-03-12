const byte segmentPins[9] = {
  2,3,4,5,6,7,8,9,10};
const byte digits[10] = {
  0b11111100, //zero
  0b01100000, //one
  0b11011010, //two
  0b11110010, //three
  0b01100110, //four
  0b10110110, //five
  0b10111110, //six
  0b11100000, //seven
  0b11111110, //eight
  0b11100110  //nine
};

const char boobies[7] = {
  8,0,0,8,1,3,5};
  
void setup() {
  setOutputs();
  displayClear();
}

void loop() {
  int potVal;
  for(int i = 0; i < sizeof(boobies); i++){
    potVal = analogRead(A0)/5;
    displayChar(boobies[i]);
    delay(potVal * 3);
    displayClear();
    delay(potVal);

  }
  delay(potVal * 5); 
}

void setOutputs() {
  for(int pin = 0; pin < sizeof(segmentPins); pin++){
    pinMode(segmentPins[pin], OUTPUT);
  }
};

void displayClear() {
  for(int pin = 0; pin < sizeof(segmentPins); pin++){
    digitalWrite(segmentPins[pin], HIGH);
  }
}

void displayChar(char val){
  digitalWrite(segmentPins[0], ((digits[val] & 128)?LOW:HIGH)); // segment a 
  digitalWrite(segmentPins[1], ((digits[val] & 64)?LOW:HIGH)); // segment b
  digitalWrite(segmentPins[2], ((digits[val] & 32)?LOW:HIGH)); // segment c
  digitalWrite(segmentPins[3], ((digits[val] & 16)?LOW:HIGH)); // segment d
  digitalWrite(segmentPins[4], ((digits[val] & 8)?LOW:HIGH)); // segment e
  digitalWrite(segmentPins[5], ((digits[val] & 4)?LOW:HIGH)); // segment f
  digitalWrite(segmentPins[6], ((digits[val] & 2)?LOW:HIGH)); // segment g
}

