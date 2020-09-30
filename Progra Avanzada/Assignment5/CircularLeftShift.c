#include <stdio.h>
#include <stdlib.h>

int circularShiftLeft(int n1, int n2){

  for(int i = 0; i < n2; i++){
    n1 =  (n1 << 1) | (n1 < 0);
  }
  return n1;
}


int main(int argc, char const *argv[]) {
  int n1;
  int n2;

  scanf("%d", &n1);
  scanf("%d", &n2);

  printf("%u", circularShiftLeft(n1, n2));
  return 0;
}
