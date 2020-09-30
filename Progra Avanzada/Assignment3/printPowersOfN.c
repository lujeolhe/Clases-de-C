#include <stdio.h>



void printPowersOfN(int n1, int n2){
  int result = 1;
  for (int i = 0; i < n2 + 1; i++) {
    printf("%d", result);
    if(i < (n2)){
      printf(" ");
    }
    result *= n1;
  }

}

int main(int argc, char const *argv[]) {
  int n1;
  int n2;
  scanf("%d", &n1);
  scanf("%d", &n2);
  printPowersOfN(n1, n2);
  return 0;
}
