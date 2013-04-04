// MAP display, uses 8 digit display and MAP sensor 
// Displays current Manifold Pressure on digits 7-4.  
// Displays peak MAP value on digits 3-0
// Reset button resets peak value

// 7-segment led driver library
#include <LedControl.h>
#include <avr/interrupt.h>

// arduino pin assignments
#define PIN_LED_DIN 12
#define PIN_LED_CLK 11
#define PIN_LED_LOAD 10
#define PIN_PEAK_RESET 0 
#define PIN_SENSOR_ADC A0
#define MAX_DIGIT_CURRENT 7
#define MAX_DIGIT_PEAK 3
#define OVERSAMPLE 64
#define OS_MULTIPLIER 2

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
  //sei();
  //EIMSK |= (1 << INT0);
  //EICRA |= (1 << ISC01);
  pinMode(PIN_SENSOR_ADC, INPUT);
}

void updateDisplayPeak() {
  updateFourDigits(MAX_DIGIT_PEAK, getPeakAsKpa()); 
}

void updateDisplayCurrent() {
  updateFourDigits(MAX_DIGIT_CURRENT, getCurrentAsKpa());
}

int getCurrentAsKpa() {
  return (kpaFromAdc(adcCurrent));
}

int getPeakAsKpa() {
  return (kpaFromAdc(adcCurrent));
}

void updateFourDigits (byte maxDigitIndex, int value) {
  lc.setDigit(0, (maxDigitIndex - 3), (value % 10), false); 
  lc.setDigit(0, (maxDigitIndex - 2), (value / 10 % 10), false);
  lc.setDigit(0, (maxDigitIndex - 1), (value / 100 % 10), false);
  lc.setDigit(0, maxDigitIndex, (value / 1000 % 10), false);
}

void peakReset() {
  adcPeak = adcCurrent;  
  updateDisplayPeak();
}
/*
ISR(EXT_INT0_vect) {
    
}
*/
int kpaFromAdc(int adc) {
  return kpaFromVolts(voltsFromAdc(adc));
}

int kpaFromVolts(float volts) {
  return (int)((volts/5+0.04)/0.004);
}

float voltsFromAdc(int adc) {
  return (float)(adc * 5) / 1024;
}

int readAdc() {
  unsigned int sampleSum2 = 0;
  for (int ii = 0; ii < OS_MULTIPLIER; ii++) {
    unsigned int sampleSum = 0;
    for (int i = 0; i < OVERSAMPLE; i++) {
      sampleSum += analogRead(PIN_SENSOR_ADC); 
    }
    sampleSum2 += sampleSum / OVERSAMPLE;
  }
  return sampleSum2 / OS_MULTIPLIER;
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
