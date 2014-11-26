#ifndef FLOODY_STATE
#define FLOODY_STATE
#include <curses.h>
#include <stdio.h>
#include "settings.h"
#include "board.h"

void save_game(Board *board){
  FILE *game;

  game = fopen("./save", "w+");
  fprintf(game, "%i\n", board->tries);

  fclose(game);

  //mvprintw(BOARD_SIZE, 2, "Game saved!");
}

void load_game(Board *board){
  FILE *game;

  game = fopen("./save", "r");

  if(game == NULL){
    mvprintw(BOARD_SIZE, 0, "Could not open savefile");
  }

  fscanf(game, "%i", &(board->tries));

  fclose(game);

  //mvprintw(BOARD_SIZE + 3, 0, "Game loaded!");
}

#endif
