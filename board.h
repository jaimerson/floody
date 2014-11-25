#ifndef FLOODY_BOARD
#define FLOODY_BOARD
#include <stdlib.h>
#include <time.h>
#include "settings.h"
#include "colors.h"

typedef struct _board {
  Color tiles[BOARD_SIZE][BOARD_SIZE];
  int tries;
} Board;

void setup_board(Board *board){
  int i, j;
  srand(time(NULL));
  board->tries = 0;

  for(i = 0; i < BOARD_SIZE; i++){
    for(j = 0; j < BOARD_SIZE; j++){
      board->tiles[i][j] = rand() % 6;
    }
  }
}

#endif
