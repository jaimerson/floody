#ifndef FLOODY_CORE
#define FLOODY_CORE
#include "settings.h"
#include "keys.h"
#include "utils.h"

void flood_fill(Color *tiles, int line, int column, Color target, Color replacement){
  if(line < 0 || column < 0 || line > BOARD_SIZE || column > BOARD_SIZE){
    return;
  }

  if(target != replacement && tiles[line * BOARD_SIZE + column] == target){
    tiles[line * BOARD_SIZE + column] = replacement;
    flood_fill(tiles, line, column + 1, target, replacement);
    flood_fill(tiles, line, column - 1, target, replacement);
    flood_fill(tiles, line - 1, column, target, replacement);
    flood_fill(tiles, line + 1, column, target, replacement);
  }
}

void flood(Board *board, Key code){
  Color target = board->tiles[0][0];
  flood_fill(&(*board).tiles, 0, 0, target, key_to_color(code));
}

int won(Board *board){
  int i, j, current;

  for(i = 0; i < BOARD_SIZE; i++){
    for(j = 0; j < BOARD_SIZE; j++){
      current = board->tiles[i][j];
      if(current != board->tiles[i + 1][j + 1]){
        return 0;
      }
    }
  }
  return 1;
}

#endif
