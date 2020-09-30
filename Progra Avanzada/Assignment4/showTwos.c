#include <stdio.h>

void showTwos(int n1){
  if(n1 % 2 != 0){
    printf("%d = %d", n1, n1);
    return;
  }

  int valorActual = n1;
  printf("%d = ", n1);
  while(valorActual % 2 == 0){
    valorActual /= 2;
    printf("2 * ");
  }

  printf("%d", valorActual);
}

int main(int argc, char const *argv[]) {
  int n1;
  scanf("%d", &n1);

  showTwos(n1);
  return 0;
}
