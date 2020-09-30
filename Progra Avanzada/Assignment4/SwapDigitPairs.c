#include <stdio.h>

void swapDigitPairs(int n1){
  int auxN = n1;
  int numberOfDigits = 1;
  int flag = 0;

  while(flag != 1){
    auxN = auxN / 10;
    numberOfDigits++;
    if(auxN < 10){
      flag = 1;
    }
  }

  int arrNum[numberOfDigits];
  int numberToMod = 10;
  auxN = n1;

  for(int i = numberOfDigits-1; i>=0;i--){
    arrNum[i] = auxN % numberToMod;
    auxN /= 10;
  }

  int initial = 0;
  if(numberOfDigits % 2 != 0){
    initial = 1;
  }

  int leftAv = 0;

  for(int i = initial; i < numberOfDigits-1; i++)
  {
    int aux;
    if(arrNum[i]%2==0){
      aux = arrNum[i];
      arrNum[i] = arrNum[i+1];
      arrNum[i+1] = aux;
      i++;
    }
  }

  for(int i = 0; i<numberOfDigits; i++){
    printf("%d", arrNum[i]);
  }

}

int main(int argc, char const *argv[]) {
  int n1;
  scanf("%d", &n1);

  swapDigitPairs(n1);
  return 0;
}
