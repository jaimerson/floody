#ifndef FLOODY_CONTROLS
#define FLOODY_CONTROLS
#include "floody.h"

void handle_keyboard_event(Key code, Board *board){
  if(code >= 49 && code <= 54){
    flood(board, code);
  }
}
#endif
