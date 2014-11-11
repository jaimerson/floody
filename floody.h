#ifndef FLOODY_CORE
#define FLOODY_CORE
#include "keys.h"

void flood(Board *board, Key code){
  if(board->tiles[0][0] != code){
    printw("%i", code);
    board->tiles[0][0] = 1;
    printw("\t%i", board->tiles[0][0]);
    refresh();
  }
}
#endif
