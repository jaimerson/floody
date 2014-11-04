#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"

int main(){
  setup();

  Board board;
  setup_board(&board);

  play(&board);
  return 0;
}
