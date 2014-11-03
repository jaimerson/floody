#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"
#define BOARD_SIZE 15

int main(){
  setup();

  Board board;

  setup_board(&board, BOARD_SIZE);

  play(&board);
  return 0;
}
