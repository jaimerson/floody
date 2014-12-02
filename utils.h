#ifndef FLOODY_UTILS
#define FLOODY_UTILS
#include <curses.h>
#include "keys.h"
#include "colors.h"

int index_of(int element, int array[], int array_size){
  int i;
  for(i = 0; i < array_size; i++){
    if(array[i] == element){
      return i;
    }
  }
  return -1;
}

Color key_to_color(Key code){
  int colors[] = { 49, 50, 51, 52, 53, 54 };
  int color = (Color) index_of(code, colors, 6);
  return color;
}

#endif
