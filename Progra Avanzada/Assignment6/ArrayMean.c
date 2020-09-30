#include "stdio.h"
#define SIZE 10

int main(void) {
  unsigned int h[SIZE] = {0};
  scanf("%u%u%u%u%u%u%u%u%u%u", &h[0], &h[1], &h[2], &h[3], &h[4], &h[5], &h[6], &h[7], &h[8], &h[9]);

  double mean = 0;
  for(int i = 0; i < 10; i++){
    mean += h[i];
  }

  mean /= 10;

  printf("%.1f", mean);

  return 0;
}
