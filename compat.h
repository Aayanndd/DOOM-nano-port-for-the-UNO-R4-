// compat.h  – tiny helpers so AVR‑only PROGMEM code also works on ARM
#pragma once
#include <Arduino.h>

#if !defined(__AVR__)
  #ifndef PROGMEM
    #define PROGMEM
  #endif
  #ifndef pgm_read_byte
    #define pgm_read_byte(addr) (*(const uint8_t *)(addr))
  #endif
  #ifndef pgm_read_word
    #define pgm_read_word(addr) (*(const uint16_t *)(addr))
  #endif
#endif
