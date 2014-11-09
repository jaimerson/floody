#ifndef FLOODY_UTILS
#define FLOODY_UTILS
#include <curses.h>

void log_if_debug(char *message){
  if(getenv("DEBUG")){
    mvprintw(0, LINES-1, *message);
  }
}
#endif
