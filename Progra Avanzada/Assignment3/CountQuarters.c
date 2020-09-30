#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  int last2 = n % 100;

  printf("%d", last2 / 25);
  return 0;
}
