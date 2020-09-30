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

int swapBits(int n1, int n2, int n3){

  char cadena[33];
  for(int i = 0; i < 33; i++){
    cadena[i] = 0;
  }

  int length = 0;

  cambiarABinarioDe32Bits(n1, cadena, &length);
  int n2O = n2;
  int n3O = n3;
  n2 = length - 1 - n2;
  n3 = length -1 - n3;

  int aux = n3O - n2O;
  if(aux % 2 == 0){
    aux /= 2;
  }

  else{
    aux = (aux - 1) / 2;
  }

  for(int i = 0; i < aux; i++){
    char cn2 = cadena[n2];
    char cn3 = cadena[n3];

    cadena[n2] = cn3;
    cadena[n3] = cn2;
     n2--;
     n3++;
  }



  return bitADecimal(cadena, length);


}


int main(int argc, char const *argv[]) {
  int n1;
  int n2;
  int n3;

  scanf("%d", &n1);
  scanf("%d", &n2);
  scanf("%d", &n3);

  printf("%d", swapBits(n1, n2, n3));
  return 0;
}
