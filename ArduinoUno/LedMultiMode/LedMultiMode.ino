/*
 * Switch test program
 */

int switchPin = 2;              // Switch connected to digital pin 2
int buttonPress;
int ledMode = 0;
const int LED_MODE_COUNT = 3;

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(switchPin, INPUT);    // sets the digital pin as input to read switch
  buttonPress = digitalRead(switchPin);
}

void loop()                     // run over and over again
{
  int val = digitalRead(switchPin);
 
  if(CheckBounce(val))
  {
    if(val != buttonPress)
    {
      if(val == LOW)
      {
        ledMode += 1;
        ledMode %= LED_MODE_COUNT;
      }
    }
    buttonPress = val;
  }

  if(ledMode == 0)
  {
    digitalWrite(LED_BUILTIN,LOW);
  }

  if(ledMode == 1)
  {
    digitalWrite(LED_BUILTIN,HIGH);
  }

  if(ledMode == 2)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN,LOW);
    delay(100);
  }   
}

// Physical buttons have springs that can bounce causing unwanted state changes
// Asserting the value is not rapidly changing is a quick fix for this
bool CheckBounce(int val1){
  delay(20);
  int val2 = digitalRead(switchPin);
  return val1 == val2;
}
