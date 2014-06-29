#include "Spark_NeoPixel.h"

#define STRIP_PIN D3

#define STRIP_LENGTH (6)

Adafruit_NeoPixel strip(STRIP_LENGTH, STRIP_PIN, WS2812B);

static void setupStrip(Adafruit_NeoPixel &strip);
static void rainbow(Adafruit_NeoPixel &strip, uint16_t counter);
static uint32_t Wheel(Adafruit_NeoPixel &strip, byte WheelPos);

void setup()
{
	setupStrip(strip);
}

static uint32_t Counter = 0;

void loop()
{
	rainbow(strip, Counter);
	delay(20);
	Counter++;
}

static void setupStrip(Adafruit_NeoPixel &pixel_strip)
{
	// Initialize all pixels to 'off'
	pixel_strip.begin();
	pixel_strip.show();
}

static void rainbow(Adafruit_NeoPixel &pixel_strip, uint16_t counter)
{
  uint16_t i;

	for(i=0; i<pixel_strip.numPixels(); i++) {
		pixel_strip.setPixelColor(i, Wheel(pixel_strip, (i+counter) & 255));
	}
  pixel_strip.show();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
static uint32_t Wheel(Adafruit_NeoPixel &pixel_strip, byte WheelPos)
{
  if(WheelPos < 85) {
   return pixel_strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return pixel_strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return pixel_strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
