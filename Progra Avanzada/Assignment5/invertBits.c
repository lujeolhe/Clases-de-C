#include <stdio.h>
#include <math.h>



int invertBits(int x, int p, int n){
  unsigned long ulx=(unsigned long)x;
  unsigned long masc  = 0x00000001;

  masc = masc<<(p-1);

  int contador = 0;
  // printf("%s\n", cadena);
  for(int i = 0; contador < n; i++){
    x=(x&~(masc<<i)) | (~(x&masc<<i)&(masc<<i));
    contador++;
  }

  // printf("%s\n", cadena);

  return x;
}

int main(int argc, char const *argv[]) {
  int x;
  int n;
  int p;

  scanf("%d", &x);
  scanf("%d", &p);
  scanf("%d", &n);

  printf("%d", invertBits(x, p, n));
  return 0;
}
