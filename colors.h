#include <curses.h>
#ifndef FLOODY_COLORS
#define FLOODY_COLORS

typedef enum {
  RED,
  BLUE,
  WHITE,
  GREEN,
  YELLOW,
  CYAN
} Colors;

void init_colors(){
  init_pair(RED, COLOR_WHITE, COLOR_RED);
  init_pair(BLUE, COLOR_WHITE, COLOR_BLUE);
  init_pair(WHITE, COLOR_BLACK, COLOR_WHITE);
  init_pair(GREEN, COLOR_WHITE, COLOR_GREEN);
  init_pair(YELLOW, COLOR_BLACK, COLOR_YELLOW);
  init_pair(CYAN, COLOR_WHITE, COLOR_CYAN);
}

#endif
