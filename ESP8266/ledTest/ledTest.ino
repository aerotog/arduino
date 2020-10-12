// The ESP8266 pin order MUST be declared before including FastLED
// See more details here: https://github.com/FastLED/FastLED/wiki/ESP8266-notes
#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <FastLED.h>

#define LED_PIN   D1
#define CHIPSET   WS2812
#define NUM_LEDS  40

CRGB leds[NUM_LEDS];

int mode;

void setup() {
  Serial.begin(9600);

  FastLED.setBrightness(255);
  FastLED.addLeds<CHIPSET, LED_PIN, GRB>(leds, NUM_LEDS);

  mode = 0;
}

uint8_t gHue = 0;
uint8_t gHueDelta = 3;

void loop() {
  //  for (int i = 0; i < NUM_LEDS; i += 3)
  //  {
  //    if ((mode + i/3) % 3 == 0){
  //      leds[i] = CRGB::HotPink;
  //    }
  //    else if((mode + i/3) % 3 == 1){
  //      leds[i] = CRGB::Green;
  //    }
  //    else if((mode + i/3) % 3 == 2){
  //      leds[i] = CRGB::Blue;
  //    }
  //  }

  gHue += gHueDelta; // compute new hue value, automatically in range

//  leds[21] = CRGB::White;
//  leds[21] = CHSV(gHue, 255, 100);

  fill_gradient(leds, 0, CHSV(mode,255,100), NUM_LEDS-1, CHSV((mode+1)%255,255,100), LONGEST_HUES);

//  FastLED.setBrightness(150);
//  fill_solid(leds, NUM_LEDS, CRGB::FairyLight   );
  

  FastLED.show();
  delay(10);
  mode += 1;
  mode %= 255;
}
