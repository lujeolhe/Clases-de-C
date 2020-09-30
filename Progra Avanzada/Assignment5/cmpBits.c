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
    }
  }

  return cuenta;
}

int cmp_bits(int a, int b){
  char arrA[33];
  char arrB[33];
  int lenA = 0;
  int lenB = 0;

  for(int i = 0; i < 33; i++){
    arrA[i] = 0;
    arrB[i] = 0;
  }

  cambiarABinarioDe32Bits(a, arrA, &lenA);
  cambiarABinarioDe32Bits(b, arrB, &lenB);

  // printf("%s -- %s\n", arrA, arrB);

  int countA = count(arrA, lenA);
  int countB = count(arrB, lenB);

  // printf("%d, %d\n", countA, countB);

  if(countA < countB){
    return -1;
  }

  else if(countA == countB){
    return 0;
  }

  else{
    return 1;
  }
}

int main(int argc, char const *argv[]) {
  int a;
  int b;

  scanf("%d", &a);
  scanf("%d", &b);

  printf("%d", cmp_bits(a, b));

}
