#include "stdio.h"
int main(void) {
  int low;
  scanf("%d", &low);
  int high;
  scanf("%d", &high);
  int sum = 0;
  for(int i = low; i <= high; i++){
    sum+= i;
  }


printf("low? high? sum = %d", sum);

return 0;
}
