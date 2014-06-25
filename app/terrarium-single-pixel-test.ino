// This #include statement was automatically added by the Spark IDE.
#include "Spark_NeoPixel.h"

#define LED0 A0
#define LED1 A1
#define LED2 A2
#define LED3 A3
#define LED4 A4

#define PIXELS0 (47)
#define PIXELS1 (51)
#define PIXELS2 (51)
#define PIXELS3 (51)

Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(PIXELS1, LED0, WS2812B);

void setup() {
    strip0.begin();
    strip0.show(); // Initialize all pixels to 'off'
	}

void loop() {
    rainbow(20);
}

static void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip0.numPixels(); i++) {
      strip0.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip0.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
static uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip0.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip0.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip0.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
