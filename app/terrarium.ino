#include "Spark_NeoPixel.h"

#define STRIP_PIN_0 A0
#define STRIP_PIN_1 A1
#define STRIP_PIN_2 A2
#define STRIP_PIN_3 A3
#define STRIP_PIN_4 A4

#define STRIP_LENGTH_0 (47)
#define STRIP_LENGTH_1 (51)
#define STRIP_LENGTH_2 (51)
#define STRIP_LENGTH_3 (51)
#define STRIP_LENGTH_TOTAL (STRIP_LENGTH_0+STRIP_LENGTH_1+STRIP_LENGTH_2+STRIP_LENGTH_3)

#define MAX_AMPS (10) // Power supply can probably spike past this, but this is the max rated continuous
#define MILLI_AMPS_PER_CHANNEL (20) // Twenty milliamps per pixel per channel, so 60mA at peak white

Adafruit_NeoPixel strip0(STRIP_LENGTH_0, STRIP_PIN_0, WS2812B);
Adafruit_NeoPixel strip1(STRIP_LENGTH_1, STRIP_PIN_1, WS2812B);
Adafruit_NeoPixel strip2(STRIP_LENGTH_2, STRIP_PIN_2, WS2812B);
Adafruit_NeoPixel strip3(STRIP_LENGTH_3, STRIP_PIN_3, WS2812B);

static void setupStrip(Adafruit_NeoPixel &strip);
static void rainbow(Adafruit_NeoPixel &strip, uint16_t counter);
static uint32_t Wheel(Adafruit_NeoPixel &strip, byte WheelPos);

typedef enum Mode {
    SolidColorMode,
    RainbowMode,
} Mode;

Mode CurrentMode = RainbowMode;

static uint32_t PrimaryColor = Adafruit_NeoPixel::Color(130, 0, 190);

static uint32_t ParseColor(String str)
{
    uint8_t r = 0, g = 0, b = 0;
    
    int commaIndex = str.indexOf(',');
    if (commaIndex > 0) {
        String redString = str.substring(0, commaIndex);
        r = redString.toInt();
        
        //  Search for the next comma just after the first
        int secondCommaIndex = str.indexOf(',', commaIndex+1);
        if (secondCommaIndex >= 0) {
            String greenString = str.substring(commaIndex+1, secondCommaIndex);
            g = greenString.toInt();

            String blueString = str.substring(secondCommaIndex+1); // To the end of the string
            b = blueString.toInt();
        } else {
            String greenString = str.substring(commaIndex+1, secondCommaIndex);
            g = greenString.toInt();
        }
    } else {
        // One value -- do grayscale
        r = g = b = str.toInt();
    }
    return Adafruit_NeoPixel::Color(r, g, b);
}

static int SetMode(String args)
{
    switch (args[0]) {
        case 'r':
            CurrentMode = RainbowMode;
            break;
        case 's':
            CurrentMode = SolidColorMode;
            break;
        default:
            break;
    }
    return CurrentMode;
}

// TOOD: Store the color in NVRAM somehow?
static int SetPrimaryColor(String args)
{
    PrimaryColor = ParseColor(args);
    return PrimaryColor;
}

void setup()
{
  Spark.function("mode", SetMode);
  Spark.function("set_color", SetPrimaryColor);
	
	setupStrip(strip0);
	setupStrip(strip1);
	setupStrip(strip2);
	setupStrip(strip3);
}

static uint32_t Counter = 0;

void loop()
{
	switch (CurrentMode) {
		case SolidColorMode:
		solid(strip0, PrimaryColor);
		solid(strip1, PrimaryColor);
		solid(strip2, PrimaryColor);
		solid(strip3, PrimaryColor);
		break;
		
		case RainbowMode:
		rainbow(strip0, Counter);
		rainbow(strip1, Counter);
		rainbow(strip2, Counter);
		rainbow(strip3, Counter);
		break;
	}
	
	delay(20);
	Counter++;
}

static void setupStrip(Adafruit_NeoPixel &pixel_strip)
{
	// Initialize all pixels to 'off'
	pixel_strip.begin();
	pixel_strip.show();
}

static void solid(Adafruit_NeoPixel &pixel_strip, uint32_t color)
{
  uint16_t i;

	for(i=0; i<pixel_strip.numPixels(); i++) {
		pixel_strip.setPixelColor(i, color);
	}
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
