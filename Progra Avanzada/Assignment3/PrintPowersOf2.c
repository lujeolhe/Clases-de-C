#include <stdio.h>



void printPowersOf2(int n){
  int result = 1;
  for (int i = 0; i < n + 1; i++) {
    printf("%d", result);
    if(i < (n)){
      printf(" ");
    }
    result *= 2;
  }

}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  printPowersOf2(n);
  return 0;
}
