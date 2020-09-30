#include <stdio.h>
#include <math.h>

void cambiarABinarioDe32Bits(unsigned int n, char* cadena, int* length){
  unsigned long masc = 0x80000000;
  for (int i = 0; i < 32; i++) {
    if((masc >> i)& n){
      *(cadena + *length) = ('1');
      (*length) ++;

    }
    else{
      *(cadena + *length) = ('0');
      (*length)++;


    }
  }
}

int bitADecimal(char* cadena, int length){
  int decimal = 0;
  int exponente = 0;
  for(int i = length-1; i >= 0; i--){
    if(*(cadena + i) == '1'){
      decimal+= pow(2, exponente);
    }
    exponente++;
  }
  return decimal;
}

int invertBits(int x, int p, int n){
  char cadena[33];
  for(int i = 0; i < 33; i++){
    cadena[i] = 0;
  }

  int length = 0;

  cambiarABinarioDe32Bits(x, cadena, &length);
  int contador = 0;
  // printf("%s\n", cadena);
  for(int i = length - p - 1; contador < n; i--){
    if(*(cadena + i) == '1'){
      *(cadena + i) = '0';
    }

    else{
      *(cadena + i) = '1';
    }

    contador++;
  }

  // printf("%s\n", cadena);

  return bitADecimal(cadena, length);
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
