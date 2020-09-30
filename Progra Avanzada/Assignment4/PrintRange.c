#include <stdio.h>

void printRange(int n1, int n2){
  if(n1 == n2){
    printf("%d", n1);
  }

  else if(n1 > n2){
    for(int i = n1; i>= n2; i--){
      printf("%d ", i);
    }
    printf("\n");
  }

  else{
    for(int i = n1; i <= n2; i++){
      printf("%d ", i);
    }
    printf("\n");
  }
}


int main(int argc, char const *argv[]) {
  int n1;
  int n2;

  scanf("%d", &n1);
  scanf("%d", &n2);

  printRange(n1, n2);
  return 0;
}
