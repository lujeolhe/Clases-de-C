#include "stdio.h"

void ftoc(double tempf, double* tempc) {
    *tempc = (tempf - 32) * 5 / 9;
}


int main(void) {

double tempf = 98.6;
double tempc = 0.0;
ftoc(tempf, &tempc);
printf("Body temp in C is: %.1f", tempc);

return 0;
}
