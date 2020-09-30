#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  if (n % 2 == 0) {
    printf("even\n");
    return 0;
  }

  printf("odd\n");
  return 0;
}
