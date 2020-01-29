#include <Arduino.h>
#include <FastLED.h>
#include <Visualization.h>

// FAST LED
#define NUM_LEDS 703
#define DISPLAY_LED_PIN 2

CRGB leds[NUM_LEDS];

#define SATURATION 244

DEFINE_GRADIENT_PALETTE( scalegradient ) {   // this is the red/orange palette
  0,   255, 72,  9,   //start pixel color
 92,   255,  0,  32,   //scale red
218,   255,102,  0,   //scale orange
255,   255, 72,  9 }; //end pixel color

// DEFINE_GRADIENT_PALETTE( scalegradient ) {   // this is the red/orange palette
//   0,   255, 72,  2,   //start pixel color
//  92,   255,  0,  8,   //scale red
// 218,   255,102,  0,   //scale orange
// 255,   255, 72,  2 }; //end pixel color

// DEFINE_GRADIENT_PALETTE( scalegradient ) {   // this is the green/yellow palette
//   0,   167,210, 46,   //start pixel color
//  92,    63,183, 72,   //scale green
// 218,   209, 22, 36,   //scale yellow
// 255,   167,210, 46 }; //end pixel color

// DEFINE_GRADIENT_PALETTE( scalegradient ) {   // this is the purple/blue palette
//   0,    70, 93,174,   //start pixel color
//  92,   155, 45,145,   //scale purple
// 218,    35,113,185,   //scale blue
// 255,   70,  93,174 }; //end pixel color


Visualization * all;

CRGBPalette256 currentPalette(scalegradient);
TBlendType currentBlending = LINEARBLEND;

void setup() {
  delay(1000);

  Serial.begin(9600);
  Serial.println("setup started");

  // DISPLAY STUFF
  FastLED.addLeds<NEOPIXEL, DISPLAY_LED_PIN>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );;
  all = new Visualization(NUM_LEDS, 1, 0, 0, leds);

  //FastLED.setBrightness(32);
  all->setAllCRGB(0x003000);
  FastLED.show();
  delay(1000);

  Serial.println("setup complete");
}

void fillIt() {  // this fills the LEDs with the gradient specified above
    for (int i=0; i< NUM_LEDS; i++) {
        leds[i] = ColorFromPalette(currentPalette, i*256/NUM_LEDS);
    }
}

void loop() {
  all->setAllCRGB(0x000000);  // this only clears the array, not the LEDs, it's fine at the top

  // all->setAllCRGB(0xFF0008);  // this changes all LEDs to the same color

  fillIt();
  FastLED.show();
}
