#define FASTLED_ESP8266_RAW_PIN_ORDER

#include <FastLED.h>

#define LED_PIN     13
#define CHIPSET WS2812 
#define NUM_LEDS    220

#define BRIGHTNESS 100
CRGB leds[NUM_LEDS];

#define BRIGHTNESS 122   /* Control the brightness of your leds */
#define SATURATION 255   /* Control the saturation of your leds */

void setup() {
  Serial.begin(9600);

//  pinMode(LED_PIN, OUTPUT);
  FastLED.setBrightness(255);
//  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812, D1, GRB>(leds, NUM_LEDS);
  
  
}

void loop() {
  for (int j = 0; j < 255; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(i - (j * 2), SATURATION, BRIGHTNESS); /* The higher the value 4 the less fade there is and vice versa */ 
    }
    FastLED.show();
    delay(5); /* Change this to your hearts desire, the lower the value the faster your colors move (and vice versa) */
  }
}
