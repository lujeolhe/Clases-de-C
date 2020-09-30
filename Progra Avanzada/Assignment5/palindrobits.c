#include <stdio.h>

int contar(int a){
  unsigned long masc = 0x80000000;
  unsigned long ula = (unsigned long )a;
  int cuenta = 0;
  int length=32;
  for(int i = 0; i < length; i++){
    if(!((masc >> i)& ula)){
      cuenta++;

    }
    else
      break;
  }
  return 32-cuenta;
}
int esPalindroBit(int a){
  unsigned long ula=(unsigned long)a;
  unsigned long masc = 0x80000000;
  unsigned long masc2 = 0x00000001;
  if(!ula){return 1;}
  int len=contar(a);
  masc=masc>>(32-len);

for(int i = 0; i < len/2-1; i++){

    if((((masc>>i)&ula)>>(len-1-i) != ((masc2<<i)&ula)>>i)){
    return 0;
    }

  }
  return 1;

}


int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  // printf("%s\n", arreglo);
  printf("%d\n", esPalindroBit(n));
  return 0;
}
