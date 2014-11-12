#ifndef FLOODY_CORE
#define FLOODY_CORE
#include "settings.h"
#include "keys.h"
#include "utils.h"

void flood_fill(Color *tile, Color target, Color replacement){
//  printw("target: %i - replacement: %i - tile: %i\n", target, replacement, *tile);
  if(target != replacement && *tile != replacement){
    *tile = replacement;
    flood_fill(tile + 1, target, replacement);
//    flood_fill(tile + BOARD_SIZE, target, replacement);
  }
}

void flood(Board *board, Key code){
  Color target = board->tiles[0][0];
  flood_fill(&board->tiles, target, key_to_color(code));
}

#endif
