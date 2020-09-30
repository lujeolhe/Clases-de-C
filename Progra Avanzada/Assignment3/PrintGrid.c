#include <stdio.h>

void printGrid(int n1, int n2){
  int vInicial = 1;
  int valor = vInicial;
  int acum = 0;

  while(vInicial <= n1){
    printf("%d", valor);
    valor += n1;
    acum++;
    if(acum < n2){
      printf(", ");
    }

    else{
      printf("\n");
      acum = 0;
      vInicial ++;
      valor = vInicial;
    }
  }
}

int main(int argc, char const *argv[]) {
  int n1;
  int n2;
  scanf("%d", &n1);
  scanf("%d", &n2);
  printGrid(n1, n2);
  return 0;
}
