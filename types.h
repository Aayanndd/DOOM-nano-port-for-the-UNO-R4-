#ifndef _types_h
#define _types_h

#define UID_null  0

// Entity types (legend applies to level.h)
#define E_FLOOR             0x0   // . (also null)
#define E_WALL              0xF   // #
#define E_PLAYER            0x1   // P
#define E_ENEMY             0x2   // E
#define E_DOOR              0x4   // D
#define E_LOCKEDDOOR        0x5   // L
#define E_EXIT              0x7   // X
// collectable entities >= 0x8
#define E_MEDIKIT           0x8   // M
#define E_KEY               0x9   // K
#define E_FIREBALL          0xA   // not in map

typedef uint16_t UID;
typedef uint8_t  EType;

struct Coords {
  double x;
  double y;
};

UID create_uid(EType type, uint8_t x, uint8_t y);
EType uid_get_type(UID uid);

Coords create_coords(double x, double y);
uint8_t coords_distance(Coords* a, Coords* b);

#endif

// ----------------------
// Entity states
// ----------------------
#define S_STAND   0
#define S_ALERT   1
#define S_FIRING  2
#define S_MELEE   3
#define S_HIT     4
#define S_DEAD    5
#define S_HIDDEN  6

// ----------------------
// Entity definitions
// ----------------------

#define MAX_ENTITIES         16
#define MAX_STATIC_ENTITIES  16

struct Entity {
  UID uid;
  uint8_t state;
  uint8_t timer;
  uint8_t last_timer;
  uint8_t walk_cycle;
  Coords pos;
  double distance;
  uint8_t health;  // ← Add this at the end of struct Entity
};

struct StaticEntity {
  UID uid;
  Coords pos;
};

struct Player {
  Coords pos;
  Coords dir;
  Coords plane;
  double velocity;
  double walk_cycle;
  uint8_t health;
  uint8_t keys;
  uint8_t hurt_timer;
};

// ----------------------
// Factory functions
// ----------------------

Player create_player(uint8_t x, uint8_t y);
Entity create_enemy(uint8_t x, uint8_t y);
Entity create_medikit(uint8_t x, uint8_t y);
Entity create_key(uint8_t x, uint8_t y);
Entity create_fireball(double x, double y, int16_t dir);

