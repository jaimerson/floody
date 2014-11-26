#ifndef FLOODY_GAME
#define FLOODY_GAME
#include <curses.h>
#include "settings.h"
#include "colors.h"
#include "board.h"
#include "keys.h"
#include "controls.h"

void teardown();
void draw_tile(int, int, int);
void draw_board(Board*);
void draw_menu(Board*);
void print_message(char[]);
char turn(Board*);
int game_is_over(Board*);

void setup(){
  initscr();
  noecho();
  curs_set(FALSE);
  start_color();
  init_colors();
}

void play(Board *board){
  Key key;
  while(key != QUIT_KEY && !game_is_over(board)){
    key = turn(board);
    handle_keyboard_event(key, board);
    draw_board(board);
    draw_menu(board);
  }
  teardown();
}

int game_is_over(Board *board){
  if(won(board)){
    print_message("GANHOU!!!11");
    return 1;
  } else if(lost(board)){
    print_message("PERDEU!!!11");
    return 1;
  }else{
    return 0;
  }
}

void print_message(char string[]){
  clear();
  mvprintw(0, 0, string);
}

char turn(Board *board){
  draw_board(board);
  return getch();
}

void draw_board(Board *board){
  int i, j;
  for(i = 0; i < BOARD_SIZE; i++){
    for(j = 0; j < BOARD_SIZE; j++){
      draw_tile(board->tiles[i][j], i, j);
    }
  }
}

void draw_menu(Board *board){
  int tries_line = BOARD_SIZE + 2;
  int help_line = tries_line + 1;
  mvprintw(tries_line, 0, "%i tentativas restantes", MAX_TRIES - board->tries);
  mvprintw(help_line, 0, "Press q to exit, and numbers 1 to 6 to play.");
}

void draw_tile(tile, line, column){
  char color = tile + 1;
  attron(COLOR_PAIR(color));
  mvprintw(line, column, "%i", color);
  refresh();
  attroff(COLOR_PAIR(color));
}

void teardown(){
  endwin();
  exit(2);
}

#endif
