
int const ledPinRed   = 6;
int const ledPinGreen = 5;
int const ledPinBlue  = 3;
int red        = 0;
int green      = 0;
int blue       = 0;
int redOld     = 0;
int greenOld   = 0;
int blueOld    = 0;

void setup()
{
  pinMode(ledPinRed,   OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue,  OUTPUT);
}

void loop()
{
  randomSeed(analogRead(A5)+analogRead(A4));
//  int red   = random(0,230);
//  int green = random(0,255);
//  int blue  = random(0,255);
  int green = random(0,255);
  int blue  = random(0,255-green);
  int red   = random(0,255-(green+blue));
  
  
  for (int i = 0; i <= 255; i+=2) 
  {
    setRed  (map(i, 0, 255, redOld,   red));
    setGreen(map(i, 0, 255, greenOld, green));
    setBlue (map(i, 0, 255, blueOld,  blue));
    delay(10);
  }

  redOld   = red;
  greenOld = green;
  blueOld  = blue;
}

void setRGB(int red, int green, int blue)
{
  setRed(red);
  setGreen(green);
  setBlue(blue);
}

void setRed(int val)
{
  analogWrite(ledPinRed, 255-val);
}

void setGreen(int val)
{
  analogWrite(ledPinGreen, 255-val);
}

void setBlue(int val)
{
  analogWrite(ledPinBlue, 255-val);
}
