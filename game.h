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
  for(i = 0; i < board.size; i++){
    for(j = 0; j < board.size; j++){
      draw_tile(board.tiles[i][j]);
    }
    printw("\n");
  }
  refresh();
}

void draw_tile(tile){
  attron(COLOR_PAIR(tile));
  printw("#");
  attroff(COLOR_PAIR(tile));
}

void teardown(){
  endwin();
  exit(0);
}
