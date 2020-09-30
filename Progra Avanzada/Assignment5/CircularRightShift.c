#include <stdio.h>
#include <stdlib.h>

int circularShiftRight(int n1, int n2){
  n1 = (unsigned long) n1;
  for(int i = 0; i < n2; i++){
    for(int j = 0; j < 31; j++){
      n1 =  (n1 << 1) | (n1 < 0);
    }
  }
  return n1;
}


int main(int argc, char const *argv[]) {
  int n1;
  int n2;

  scanf("%d", &n1);
  scanf("%d", &n2);

  printf("%lu", (unsigned long)circularShiftRight(n1, n2));
  return 0;
}
