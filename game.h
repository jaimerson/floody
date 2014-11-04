#include <curses.h>
#include "colors.h"
#include "board.h"

void teardown();
void draw_tile(int);
void draw_board(Board);

void setup(){
  initscr();
  start_color();
  init_colors();
}

void play(Board *board){
  draw_board(*board);
  getch();
  teardown();
}

void draw_board(Board board){
  int i, j;
  for(i = 0; i < 15; i++){
    for(j = 0; j < 15; j++){
      draw_tile(board.tiles[i][j]);
    }
    move(i, 0);
  }
  refresh();
}

void draw_tile(tile){
  char color = tile + 1;
  attron(COLOR_PAIR(color));
  printw("  %i  ", tile);
  attroff(COLOR_PAIR(color));
}

void teardown(){
  endwin();
  exit(0);
}
