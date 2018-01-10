#include <FastLED.h>
#define NUM_LEDS 20
#define DATA_PIN 2
#define TOUCHPAD1 0
#define TOUCHPAD2 1
CRGB leds[NUM_LEDS];

int threshold = 2000;

// Touch pad values
int touch1 = 0;
int touch2 = 0;

void dimAllLeds() {
  // Turn all the lights off
  for (size_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
}

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(13, OUTPUT);
}

void loop() {
    digitalWrite(13, HIGH);
    touch1 = touchRead(TOUCHPAD1);
    touch2 = touchRead(TOUCHPAD2);

    // Debugging prints
    // Serial.print("TouchPad 1 Value: "); Serial.println(touch1);

    // Turn off all lights from before
    dimAllLeds();

    // Turn on each light when each button is pressed
    if (touch1 > threshold) {
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Blue;
    }
    if (touch2 > threshold) {
      leds[2] = CRGB::Blue;
      leds[3] = CRGB::Blue;
    }

    FastLED.show();
}
