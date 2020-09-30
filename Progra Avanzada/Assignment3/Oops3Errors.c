#include "stdio.h"
void printer(double x, double y);

int main(void) {


double bubble = 867.5309;
int z = 5;
printer(10.01, 8.0);
printer(10.01, 867.5309);
printf("The value from main is: %.4f\n", bubble);
printf("z = %d\n", z);
return 0;
}

void printer(double x, double y) {

  if(y < 10.0){
    printf("x = %.2f and y = %.1f\n", x, y);
    return;
  }


  printf("x = %.2f and y = %.4f\n", x, y);
}
