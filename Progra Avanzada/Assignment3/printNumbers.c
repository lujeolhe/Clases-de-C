#include <stdio.h>

void printNumbers(int n){
  for(int i = 1; i <= n; i++){
    printf("[%d]", i);
    if(i < n){
      printf(" ");
    }
  }
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  printNumbers(n);
  return 0;
}
