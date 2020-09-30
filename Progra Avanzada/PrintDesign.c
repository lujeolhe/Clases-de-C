// Jaime Orlando López Ramos, A01374696
#include <stdio.h>

void printDesign(){
  int dashN = 5;
  for (int i = 1; i < 10; i+=2) {
    for(int j = 0; j < dashN; j++){
      printf("-");
    }

    for(int k = 0; k<i; k++){
      printf("%d", i);
    }

    for(int j = 0; j < dashN; j++){
      printf("-");
    }

    dashN--;
    printf("\n");

  }

}

int main(int argc, char const *argv[]) {
  printDesign();
  return 0;
}
