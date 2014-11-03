#ifndef FLOODY_BOARD
#define FLOODY_BOARD

typedef struct _board Board;

struct _board {
  int size;
  int **tiles;
};

void setup_board(Board *board, int size){
  board->size = size;
  int arr[size][size];
  board->tiles = (int**)arr;
}

#endif
