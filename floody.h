#ifndef FLOODY_CORE
#define FLOODY_CORE
#include "settings.h"
#include "keys.h"
#include "utils.h"

void flood_fill(Color tiles[BOARD_SIZE][BOARD_SIZE], Color *target, Color replacement){
  if(*target != replacement){
    *target = replacement;
    flood_fill(tiles, ++target, replacement);
  }
}

void flood(Board *board, Key code){
  flood_fill(board->tiles, &board->tiles[0][0], key_to_color(code));
}

#endif
