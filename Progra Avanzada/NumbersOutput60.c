// Jaime Orlando López Ramos, A01374696

#include <stdio.h>

int main(int argc, char const *argv[]) {
  for(int i = 0; i < 6; i++){
    printf("        | ");
  }

  printf("\n");
  for(int i = 0; i < 6; i++){
    for(int j = 1; j < 10; j++){
      printf("%d", j);
    }
    printf("0");
  }

  return 0;
}
