#include <curses.h>
#include "settings.h"
#include "colors.h"
#include "board.h"
#include "keys.h"
#include "controls.h"

void teardown();
void draw_tile(int);
void draw_board(Board*);
char turn(Board*);
int game_is_over(Board*);

void setup(){
  initscr();
  start_color();
  init_colors();
}

void play(Board *board){
  Key key;
  while(key != QUIT_KEY){
    if(game_is_over(board)){
      printw("WON!");
    }

    key = turn(board);
    handle_keyboard_event(key, board);
    draw_board(board);
  }
  teardown();
}

int game_is_over(Board *board){
  return won(board);
}

char turn(Board *board){
  draw_board(board);
  return getch();
}

void draw_board(Board *board){
  move(0,0);
  int i, j;
  for(i = 0; i < BOARD_SIZE; i++){
    for(j = 0; j < BOARD_SIZE; j++){
      draw_tile(board->tiles[i][j]);
    }
    move(i, 0);
  }
  printw("%x\n", &board->tiles);
  refresh();
}

void draw_tile(tile){
  char color = tile + 1;
  attron(COLOR_PAIR(color));
  printw("  %i  ", color);
  attroff(COLOR_PAIR(color));
}

void teardown(){
  endwin();
  exit(0);
}
