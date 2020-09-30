#include <stdio.h>

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

int cmp_bits(int a, int b){
  unsigned long ula=(unsigned long)a;
  unsigned long ulb=(unsigned long)b;

  // printf("%s -- %s\n", arrA, arrB);

  int countA = count(ula);
  int countB = count(ulb);

  printf("%d, %d\n", countA, countB);

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
