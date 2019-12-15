#ifndef __CAR_H__
#define __CAR_H__

#include <Arduino.h>
#include <FastLED.h>

// LED Definitions
#define LED_PIN     11
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    33

#define BRAKE_LED_START_INDEX 6
#define BRAKE_LED_END_INDEX 13

#define LEFT_BRAKE_LED_START_INDEX BRAKE_LED_START_INDEX
#define LEFT_BRAKE_LED_END_INDEX 8

#define RIGHT_BRAKE_LED_START_INDEX 10
#define RIGHT_BRAKE_LED_END_INDEX BRAKE_LED_END_INDEX

#define LEFT_HEAD_LED_START_INDEX 29
#define LEFT_HEAD_LED_END_INDEX 31

#define RIGHT_HEAD_LED_START_INDEX 25
#define RIGHT_HEAD_LED_END_INDEX 27

#define BRAKING_BRIGHTNESS 255
#define HEADLIGHT_BRIGHTNESS 255
#define GOING_BRIGHTNESS 10

void braking();
void setBrakeLights(CRGB lightColor);
void setTurnSignal(CRGB leftColor, CRGB rightColor);

CRGB leds[NUM_LEDS];

void setupLights() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( GOING_BRIGHTNESS );
  FastLED.show();
}
void turnLeft() {
  FastLED.setBrightness(HEADLIGHT_BRIGHTNESS);
  setTurnSignal(CRGB(255,255,0), CRGB(0, 0, 0));
//  FastLED.show();
}

void turnRight() {
  FastLED.setBrightness(HEADLIGHT_BRIGHTNESS);
  setTurnSignal(CRGB(0,0,0), CRGB(255, 255, 0));
//  FastLED.show();
}

void braking() {
  FastLED.setBrightness( BRAKING_BRIGHTNESS );
  setBrakeLights(CRGB(255,0,0));
//  FastLED.show();
}

void going() {
  FastLED.setBrightness( GOING_BRIGHTNESS );
  setBrakeLights(CRGB(255,0,0));
//  FastLED.show();
}

void setBrakeLights(CRGB color) {
  for(int i = BRAKE_LED_START_INDEX; i < BRAKE_LED_END_INDEX; i++) {
    leds[i] = color;
  }
}

void setTurnSignal(CRGB left, CRGB right) {
//  for(int i = LEFT_BRAKE_LED_START_INDEX; i < LEFT_BRAKE_LED_END_INDEX; i++) {
//    leds[i] = left;
//  }

  for(int i = LEFT_HEAD_LED_START_INDEX; i < LEFT_HEAD_LED_END_INDEX; i++) {
    leds[i] = left;
  }

//  for(int i = RIGHT_BRAKE_LED_START_INDEX; i < RIGHT_BRAKE_LED_END_INDEX; i++) {
//    leds[i] = right;
//  }

  for(int i = RIGHT_HEAD_LED_START_INDEX; i < RIGHT_HEAD_LED_END_INDEX; i++) {
    leds[i] = right;
  }
}

#endif
