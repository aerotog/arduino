#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    10

int redp = A0;
int grnp = A1;
int blup = A2;

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.setBrightness(50);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}
void loop() {
  Serial.println("Starting loop");
//  int target = 0;
//  leds[target] = CRGB ( 0, 0, 255);  
//  FastLED.show();
//  delay(500);
//  leds[target] = CRGB ( 0, 255, 0);
//  FastLED.show();
//  delay(500);
//  leds[target] = CRGB ( 255, 0, 0);
//  FastLED.show();
//  delay(500);

  int redval = analogRead(redp);
  Serial.print(redval);
  Serial.print(",");

  int grnval = analogRead(grnp);
  Serial.print(grnval);
  Serial.print(",");
  
  int bluval = analogRead(blup);
  Serial.println(bluval);
//  Serial.println("HERE IS THE ANALOG");
//  Serial.println(sensorValue);

  int red = (double)redval / 1024 * 255;
  int grn = (double)grnval / 1024 * 255;
  int blu = (double)bluval / 1024 * 255;

  for(int i = 0; i < 10; i++){
    leds[i] = CRGB ( red, grn, blu);
  }

//  int calcBright = (double)sensorValue / 1024 * 50;
//
//  Serial.println("Calculated brightness");
//  Serial.println(calcBright);
//  FastLED.setBrightness(calcBright);
  FastLED.show();
  delay(100);
  
  
  
//  for(int i = 0; i < 50; i++){
//    FastLED.setBrightness(i);
//    FastLED.show();
//    delay(10);
//  }
//
//  for(int i = 50; i > 0; i--){
//    FastLED.setBrightness(i);
//    FastLED.show();
//    delay(10);
//  }

//  for(int i = 0; i < NUM_LEDS; i++){
//      leds[i] = CRGB ( 255, 0, 0);  
//      FastLED.show();
//      delay(100);
//  }
//  for(int i = NUM_LEDS; i > 0; i--){
//      leds[i] = CRGB ( 0, 0, 0);  
//      FastLED.show();
//      delay(100);
//  }
  
}
