// Jaime Orlando López Ramos, A01374696

#include <stdio.h>
#include <stdlib.h>


int lastThreeDigits(int n){
  return n % 1000;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d", lastThreeDigits(n));
  return 0;
}
