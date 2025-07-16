#ifndef _entities_h
#define _entities_h

#include "types.h"

// entity statuses
#define S_STAND               0
#define S_ALERT               1
#define S_FIRING              2
#define S_MELEE               3
#define S_HIT                 4
#define S_DEAD                5
#define S_HIDDEN              6
#define S_OPEN                7
#define S_CLOSE               8


Entity create_entity(uint8_t type, uint8_t x,  uint8_t y, uint8_t initialState, uint8_t initialHealth);
StaticEntity create_static_entity(UID uid, uint8_t x,  uint8_t y, bool active);

#endif

