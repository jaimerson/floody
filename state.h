#ifndef FLOODY_STATE
#define FLOODY_STATE
#include <curses.h>
#include <stdio.h>
#include "settings.h"
#include "board.h"

void save_game(Board *board){
  FILE *game, *tries;
  int i, j;

  tries = fopen("./tries", "w+");
  game = fopen("./save", "w+");
  fprintf(tries, "%i\n", board->tries);

  for(i = 0; i < BOARD_SIZE; i++){
    for(j = 0; j < BOARD_SIZE; j++){
      fprintf(game, "%i", board->tiles[i][j]);
    }
  }

  fclose(game);
  fclose(tries);

  //mvprintw(BOARD_SIZE, 2, "Game saved!");
}

void load_game(Board *board){
  FILE *game, *tries;
  Color *tile = &(board->tiles);

  game = fopen("./save", "r");
  tries = fopen("./tries", "r");

  if(tries == NULL || tries == NULL){
    mvprintw(BOARD_SIZE, 0, "Could not open savefile");
  }

  fscanf(tries, "%i", &(board->tries));

  while(fscanf(game, "%i", tile) != EOF){
    tile++;
  }

  fclose(game);
  fclose(tries);

  //mvprintw(BOARD_SIZE + 3, 0, "Game loaded!");
}

#endif
