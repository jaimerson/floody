#include <stdio.h>
#include "board.h"

int main(){
  Board my_board;
  printf("Type the size now.\n");

  scanf("%i", &my_board.size);
  int arr[my_board.size][my_board.size];

  int i, j;

  for(i = 0; i < my_board.size; i++){
    for(j = 0; j < my_board.size; j++){
      printf("[%i]", abs(arr[i][j] % 6));
    }
    printf("\n");
  }

  return 0;
}
