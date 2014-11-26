#ifndef FLOODY_CONTROLS
#define FLOODY_CONTROLS
#include <curses.h>
#include "floody.h"
#include "state.h"

void handle_keyboard_event(Key code, Board *board){
  if(code >= 49 && code <= 54){
    board->tries++;
    flood(board, code);
  }else if(code == 56){
    save_game(board);
  }else if(code == 57){
    load_game(board);
  }
}
#endif
