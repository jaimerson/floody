#ifndef FLOODY_CORE
#define FLOODY_CORE
#include "settings.h"
#include "keys.h"
#include "utils.h"

void flood_fill(Board *board, int line, int column, Color target, Color replacement){
  if(line < 0 || column < 0 || line >= BOARD_SIZE || column >= BOARD_SIZE){
    return;
  }
  mvprintw(BOARD_SIZE, 0, "%i - %i\n", board->tiles[line][column], target);

  if(board->tiles[line][column] == target){
    board->tiles[line][column] = replacement;
    flood_fill(board, line, column + 1, target, replacement);
    flood_fill(board, line, column - 1, target, replacement);
    flood_fill(board, line - 1, column, target, replacement);
    flood_fill(board, line + 1, column, target, replacement);
  }
}

void flood(Board *board, Key code){
  Color code_color = key_to_color(code);
  board->tiles[0][0] = code_color;
  Color target = board->tiles[0][0];
  flood_fill(board, 0, 0, target, code_color);
}

int won(Board *board){
  int i, j, current, previous;
  current = previous = board->tiles[0][0];

  for(i = 0; i < BOARD_SIZE; i++){
    for(j = 0; j < BOARD_SIZE; j++){
      current = board->tiles[i][j];
      if(current != previous){
        return 0;
      }
      previous = current;
    }
  }
  return 1;
}

#endif
