#include <stdio.h>

void cambiarABinarioDe32Bits(unsigned int n, char* cadena, int* length){
  unsigned long masc = 0x80000000;
  int bandera  = 0;
  for (int i = 0; i < 32; i++) {
    if((masc >> i)& n){
      *(cadena + *length) = ('1');
      (*length) ++;
      bandera = 1;
    }
    else if (bandera){
      *(cadena + *length) = ('0');
      (*length)++;


    }
  }
}

int count(char* arreglo, int length){
  int cuenta = 0;
  for(int i = 0; i < length; i++){
    if(*(arreglo + i) == '1'){
      cuenta++;
      // printf("%d, %d, %d\n", cuenta, length, i);


    }
  }

  return cuenta;
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  char arreglo[33];
  for(int i = 0; i < 33; i++){
    arreglo[i] = 0;
  }

  int length = 0;

  cambiarABinarioDe32Bits(n, arreglo, &length);
  // printf("%s\n", arreglo);
  printf("%d", count(arreglo, length));
  return 0;
}
