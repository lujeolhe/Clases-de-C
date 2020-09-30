#include <stdio.h>

void printSquare(int n1, int n2){

  int num = n1;
  int original = n1;
  while(original <= n2){
    for(int i = n1; i <= n2; i++){
      printf("%d", num);
      num++;
      if(num > n2){
        num = n1;
      }
    }
    printf("\n");
    num++;
    original++;
  }
}


int main(int argc, char const *argv[]) {
  int n1;
  int n2;
  scanf("%d", &n1);
  scanf("%d", &n2);
  printSquare(n1, n2);
  return 0;
}
