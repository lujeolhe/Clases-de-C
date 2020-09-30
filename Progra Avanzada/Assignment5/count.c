/////////Librerias////////////////
#include <stdio.h>

/////////Funciones////////////////
int count(unsigned long num);

////////////MAIN/////////////
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  unsigned long num=(unsigned long )n;
  printf("%d", count(num));

  return 0;
}
/////////Funciones////////////////

int count(unsigned long num){
  unsigned long masc = 0x80000000;
  int cuenta = 0;
  int length=32;
  for(int i = 0; i < length; i++){
    if((masc >> i)& num){
      cuenta++;
    }
  }
  return cuenta;
}
