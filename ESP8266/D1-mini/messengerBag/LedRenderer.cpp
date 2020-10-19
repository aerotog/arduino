#include "LedRenderer.h"
#include <math.h>

// Must declare ESP pin order before including FastLED to have correctly named pin constants
#define FASTLED_ESP8266_RAW_PIN_ORDER
#include <FastLED.h>

#define NUM_LEDS    10
#define BRIGHTNESS 120
#define SATURATION 255

CRGB leds[NUM_LEDS];
// #define LED_PIN     5
// #define CHIPSET     WS2812

LedRenderer::LedRenderer()
{
    FastLED.addLeds<WS2812, D1, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}


void LedRenderer::Render(Mode mode)
{
    if (mode == Mode::RAINBOW)
    {
      modeCounter += 1;
      modeCounter %= 255;
      
      for (int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CHSV(i + (modeCounter * 1), SATURATION, BRIGHTNESS);
      }
      FastLED.show();
      delay(50);

    }
    else if (mode == Mode::CYLON)
    {
      modeCounter += 1;
      modeCounter %= 2 * NUM_LEDS;

      int led = 0;
      
      if (modeCounter < NUM_LEDS)
      {
        led = modeCounter;
      }
      else
      {
        led = 2 * NUM_LEDS - modeCounter - 1; 
      }

      FastLED.clear(); 
      leds[led] = CRGB::Red;
      FastLED.show();

      float delayTime = GetDelayTime((float)led, (float)NUM_LEDS - 1);
      delay(delayTime);
    }
    else if (mode == Mode::CAUTION)
    {
      int maxBrightness = 200;
      
      modeCounter += 1;
      modeCounter %= (2 * maxBrightness);

      int brightness = modeCounter;
      
      
      if (modeCounter > maxBrightness)
      {
        brightness = 2 * maxBrightness - modeCounter; 
      }
      
      FastLED.setBrightness(brightness);
      
      for (int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CRGB::Yellow;
      }
      
      FastLED.show();
      delay(3);

      // Reset the brightness between renders in case the mode changes
      FastLED.setBrightness(BRIGHTNESS);      
    }
    else // Default mode is LEDs off
    {
      FastLED.clear();
      FastLED.show();
    }
}

float LedRenderer::GetDelayTime(float num, float den)
{
  float wave = sin(num / den * PI);
  return std::max(0.1f, wave) * 125;
}
