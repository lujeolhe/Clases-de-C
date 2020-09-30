/*
Jaime Orlando López Ramos, A01374696
Assignment 2, Nested Numbers
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  for(int i = 0; i<3; i++){
    for (int j = 0; j < 10; j++) {
      printf("%d%d%d", j, j, j);
      if(j == 9){
        printf("\n");
      }
    }
  }

  return 0;
}
