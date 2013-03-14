/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
#include <dht11.h>

dht11 DHT11 = dht11(D1, BUSA);//we are placing our devide on D1 on BUSA

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("fuck yes");
  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(DHT11.fahrenheit(), DEC);
 
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.print((float)DHT11.humidity, DEC);
  
  // print the number of seconds since reset:
  //lcd.print(millis()/1000);

  Serial.println("\n");

  int chk = DHT11.read();

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case 0: Serial.println("OK"); break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, DEC);

  Serial.print("Temperature (?C): ");
  Serial.println((float)DHT11.temperature, DEC);

  Serial.print("Temperature (?F): ");
  Serial.println(DHT11.fahrenheit(), DEC);
  
  Serial.print("Temperature (?K): ");
  Serial.println(DHT11.kelvin(), DEC);

  Serial.print("Dew Point (?C): ");
  Serial.println(DHT11.dewPoint(), DEC);

  Serial.print("Dew PointFast (?C): ");
  Serial.println(DHT11.dewPointFast(), DEC);
  
  delay(500);
  
}
