#include <stdio.h>

void digitSum(int n1){
  if(n1 < 0){
    n1 = n1*-1;
  }
  int numberOfDigits = 1;
  int auxN = n1;
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

  for(int i = 0; i < numberOfDigits; i++){
    arrNum[i] = auxN % numberToMod;
    auxN /= 10;
  }

  int sum = 0;

  for(int j = 0; j < numberOfDigits; j++){
    sum += arrNum[j];
  }

  printf("%d", sum);
}


int main(int argc, char const *argv[]) {
  int n1;
  scanf("%d", &n1);

  digitSum(n1);
  return 0;
}
