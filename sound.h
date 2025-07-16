#ifndef _sound_h
#define _sound_h

#include <Arduino.h>

#define SOUND_PIN 9  // Change this to any digital pin connected to your speaker

inline void sound_init() {
  pinMode(SOUND_PIN, OUTPUT);
}

inline void playSound(uint16_t frequency, uint16_t duration) {
  tone(SOUND_PIN, frequency, duration);
}

inline void off() {
  noTone(SOUND_PIN);
}

#endif
