// MAP display, uses 8 digit display and MAP sensor 
// Displays current Manifold Pressure on digits 7-4.  
// Displays peak MAP value on digits 3-0
// Reset button resets peak value

// 7-segment led driver library
#include "LedControl.h"

// arduino pin assignments
#define PIN_LED_DIN 12
#define PIN_LED_CLK 11
#define PIN_LED_LOAD 10
#define PIN_PEAK_RESET 0 
#define PIN_SENSOR_ADC A0
#define MAX_DIGIT_CURRENT 7
#define MAX_DIGIT_PEAK 3
#define OVERSAMPLE 64

// LED driver object
LedControl lc = LedControl(PIN_LED_DIN, PIN_LED_CLK, PIN_LED_LOAD, 1);

int adcCurrent;
int adcPeak;

void setup() {
  //LED Display
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0); 
  adcPeak, adcCurrent = 0;
  // Peak Reset interrupt
//  attachInterrupt(PIN_PEAK_RESET, peakReset, LOW);
  pinMode(PIN_SENSOR_ADC, INPUT);

 // digitalWrite(2, HIGH); // button press pulls PEAK_RESET LOW
                                  // release (HIGH) triggers interrupt
 // Serial.begin(9600);
}

void updateDisplayPeak() {
  updateFourDigits(MAX_DIGIT_PEAK, adcPeak); 
 // Serial.print("Peak: ");
 // Serial.println(adcPeak);
}

void updateDisplayCurrent() {
  updateFourDigits(MAX_DIGIT_CURRENT, adcCurrent);
//  Serial.print("Current: ");
 // Serial.println(adcCurrent);
}

void updateFourDigits
  (byte maxDigitIndex, int value) {
  // display 4 digits on 8 digit display
  // single decimal point (value / 10)
//  Serial.print("Digital: ");
//  Serial.print(value / 1000 % 10);  
//  Serial.print(value / 100 % 10);
 // Serial.print(value / 10 % 10);
 // Serial.print(value % 10);
 // Serial.println();
  
  lc.setDigit(0, (maxDigitIndex - 3), (value % 10), false); 
  lc.setDigit(0, (maxDigitIndex - 2), (value / 10 % 10), true);
  lc.setDigit(0, (maxDigitIndex - 1), (value / 100 % 10), false);
  lc.setDigit(0, maxDigitIndex, (value / 1000 % 10), false);
}

void peakReset() {
  adcPeak = adcCurrent;  
  updateDisplayPeak();
}

int readAdc() {
  unsigned int sampleSum = 0;
  for (int i = 0; i < OVERSAMPLE; i++) {
    sampleSum += analogRead(PIN_SENSOR_ADC); 
  }
    
  return sampleSum / OVERSAMPLE;
}

void loop() {
  int adc = readAdc();
  if (adc != adcCurrent) {
    adcCurrent = adc;
    updateDisplayCurrent();
    if (adcCurrent > adcPeak) {
      adcPeak = adcCurrent;
      updateDisplayPeak(); 
    }
  }
}
