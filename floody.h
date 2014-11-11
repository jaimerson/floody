#ifndef FLOODY_CORE
#define FLOODY_CORE
#include "settings.h"
#include "keys.h"

void flood_fill(Color *tiles[BOARD_SIZE][BOARD_SIZE], Color *target, Color replacement){
  printw("%i - %i", *target, replacement);
  if(*target != replacement){
    printw("hay");
    *target = replacement;
    flood_fill(tiles, ++target, replacement);
  }
}

void flood(Board *board, Key code){
  flood_fill(&board->tiles, &board->tiles[0][0], 2);
}

#endif
