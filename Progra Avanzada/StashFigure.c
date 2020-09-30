// Jaime Orlando López Ramos
// Assignment 2

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int slashN = 0;
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < slashN; k++) {
      printf("\\");
    }
    for (int j = 0; j < (22 - slashN * 2); j++) {
      printf("!");
    }
    for (int k = 0; k < slashN; k++) {
      printf("/");
    }
    printf("\n");
    slashN += 2;
  }
  return 0;
}
