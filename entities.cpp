#include <stdint.h>
#include "entities.h"

Player create_player(uint8_t x, uint8_t y) {
  Player p;
  p.pos = create_coords(x + 0.5, y + 0.5);
  p.dir = create_coords(-1.0, 0.0);
  p.plane = create_coords(0.0, 0.66);
  p.velocity = 0;
  p.walk_cycle = 0;
  p.health = 100;
  p.keys = 0;
  p.hurt_timer = 0;
  return p;
}

Entity create_enemy(uint8_t x, uint8_t y) {
  return create_entity(E_ENEMY, x, y, S_STAND, 100);
}

Entity create_medikit(uint8_t x, uint8_t y) {
  return create_entity(E_MEDIKIT, x, y, S_STAND, 0);
}

Entity create_key(uint8_t x, uint8_t y) {
  return create_entity(E_KEY, x, y, S_STAND, 0);
}

Entity create_fireball(double x, double y, int16_t dir) {
  return create_entity(E_FIREBALL, (uint8_t)x, (uint8_t)y, S_STAND, dir);
}

// You'll also need create_entity(...) defined
Entity create_entity(uint8_t type, uint8_t x, uint8_t y, uint8_t initialState, uint8_t initialHealth) {
  UID uid = create_uid(type, x, y);
  Coords pos = create_coords(x + 0.5, y + 0.5);
  Entity new_entity = {
    uid,
    initialState,
    0,
    0,
    0,
    pos,
    0.0,
    initialHealth
  };
  return new_entity;
}
