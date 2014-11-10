#ifndef FLOODY_CORE
#define FLOODY_CORE
#include "keys.h"

void flood(Board *board, Key code){
  if(board->tiles[0][0] != code){
    printw("%i", code);
    board->tiles[0][0] = 3;
    printw("\t%i", board->tiles[0][0]);
    refresh();
    //board->tiles[0][0] = key_to_color[code];
  }
}
#endif
