#ifndef FLOODY_CORE
#define FLOODY_CORE
#include "settings.h"
#include "keys.h"
#include "utils.h"

void flood_fill(Color *tiles, int line, int column, Color target, Color replacement){
  //printw("line: %i\ncolumn: %i\n-----",  line, column);
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

void flood(Color *tiles, Key code){
  Color code_color = key_to_color(code);
  tiles[0] = code_color;
  Color target = tiles[0];
  //flood_fill(tiles, 0, 0, target, code_color);
  printw("%x\n", tiles);
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
