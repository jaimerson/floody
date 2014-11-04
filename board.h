#ifndef FLOODY_BOARD
#define FLOODY_BOARD
#define BOARD_SIZE 15
#include <stdlib.h>

typedef struct _board {
  int size;
  char tiles[BOARD_SIZE][BOARD_SIZE];
} Board;

void setup_board(Board *board){
  int i, j;
  for(i = 0; i < BOARD_SIZE; i++){
    for(j = 0; j < BOARD_SIZE; j++){
      board->tiles[i][j] = rand() % 6;
    }
  }
}

#endif
