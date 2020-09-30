// Jaime Orlando López Ramos, A01374696

#include <stdio.h>
void slash2(int n){
  int slashN = 0;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < slashN; j++){
      printf("\\");
    }

    for (int j = 0; j < ((n*3 + (n-2))-(slashN*2)); j++) {
      printf("!");
    }

    for(int j = 0; j < slashN; j++){
      printf("/");
    }

    slashN += 2;
    printf("\n");
  }
}


int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  slash2(n);
}
