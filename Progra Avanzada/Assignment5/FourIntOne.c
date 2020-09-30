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

unsigned int bitADecimal(char* cadena, int length){
  unsigned int decimal = 0;
  int exponente = 0;
  for(int i = length-1; i >= 0; i--){
    if(*(cadena + i) == '1'){
      decimal+= pow(2, exponente);
    }
    exponente++;
  }
  return decimal;
}

unsigned int fourIntOne(unsigned int n1, unsigned int n2, unsigned int n3, unsigned int n4){
  char cadenaN1[33];
  char cadenaN2[33];
  char cadenaN3[33];
  char cadenaN4[33];
  char cadenaFinal[33];

  for(int i = 0; i < 33; i++){
    cadenaN1[i] = 0;
    cadenaN2[i] = 0;
    cadenaN3[i] = 0;
    cadenaN4[i] = 0;
    cadenaFinal[i] = 0;
  }

  int l1 = 0;
  int l2 = 0;
  int l3 = 0;
  int l4 = 0;

  cambiarABinarioDe32Bits(n1, cadenaN1, &l1);
  cambiarABinarioDe32Bits(n2, cadenaN2, &l2);
  cambiarABinarioDe32Bits(n3, cadenaN3, &l3);
  cambiarABinarioDe32Bits(n4, cadenaN4, &l4);

  int indexN = 24;
  for(int i = 0; i < 33; i++){

    if(indexN >= 32){
      indexN = 24;
    }

    if(i >= 0 && i <= 7){
      cadenaFinal[i] = cadenaN4[indexN];
    }

    else if(i >= 8 && i < 16){
      cadenaFinal[i] = cadenaN3[indexN];
    }

    else if(i >= 16 && i < 24){
      cadenaFinal[i] = cadenaN2[indexN];
    }

    else{
      cadenaFinal[i] = cadenaN1[indexN];
    }



    indexN++;
  }
  return bitADecimal(cadenaFinal, 32);

}

int main(int argc, char const *argv[]) {
  unsigned int n1;
  unsigned int n2;
  unsigned int n3;
  unsigned int n4;

  scanf("%u", &n1);
  scanf("%u", &n2);
  scanf("%u", &n3);
  scanf("%u", &n4);

  printf("%u", fourIntOne(n1, n2, n3, n4));
  return 0;
}
