#include <stdio.h>

void countFactors(int n1){
  int factors = 1;
  for(int i = n1-1; i>0; i-- ){
    if(n1 % i == 0){
      factors++;
    }
  }

  printf("%d", factors);
}

int main(int argc, char const *argv[]) {
  int n1;
  scanf("%d", &n1);

  countFactors(n1);

  return 0;
}
