#include <stdio.h>

int isPerfect(int n1);
void perfectNumbers(int n1){
  if(n1 < 6){
    printf("Perfect numbers up to %d:", n1);
    return;
  }
  printf("Perfect numbers up to %d: ", n1);

  for(int i = 1; i <= n1 ; i++){
    if(isPerfect(i)==1){
      printf("%d ", i);
    }
  }



  printf("\n");
}


int isPerfect(int n1){


  int suma = 0;
  for(int i = 1; i < n1; i++){
    if(n1%i == 0){
      suma+=i;
    }
  }

  if(suma == n1){
    return 1;
  }

  return 0;
}

int main(int argc, char const *argv[]) {
  int n1;
  scanf("%d", &n1);
  perfectNumbers(n1);
  return 0;
}
