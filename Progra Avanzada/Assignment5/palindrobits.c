#include <stdio.h>

void cambiarABinarioDe32BitsSinSigno(unsigned int n, char* cadena, int* length){
  unsigned int masc = 0x80000000;
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

int esPalindroBit(char* arreglo, int length){
  if((length==1)){return 1;}


for(int i = 0; i < length/2; i++){

    if(!(*(arreglo + i) == *(arreglo + length - i -1))){
    return 0;
    }

  }
  return 1;

}


int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  char arreglo[33];
  for(int i = 0; i < 33; i++){
    arreglo[i] = 0;
  }

  int length = 0;

  cambiarABinarioDe32BitsSinSigno(n, arreglo, &length);
  // printf("%s\n", arreglo);
  printf("%d\n", esPalindroBit(arreglo, length));
  return 0;
}
