#ifndef FLOODY_KEYS
#define FLOODY_KEYS

typedef enum _keys {
  QUIT_KEY = 113
} Key;

char key_to_color(Key code){
  int colors[] = { 49, 50, 51, 52, 53, 54, 55, 56, 57 };
  return colors[code];
}

#endif
