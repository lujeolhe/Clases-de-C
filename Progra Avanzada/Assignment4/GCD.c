#include <stdio.h>

void gcd(int n1){
  int counter = 0;
  int special = 0;
  for(int i = n1; i>1; i--){
    if(i < 9){
      special = i;
    }

    else{special = i/ 2;}

    for(int j = 2; j <= special; j++){
      if(j == special){
        counter ++;
      }
      if(i % j == 0){
        break;
      }
    }
  }
  printf("%d", counter);
}

int main(int argc, char const *argv[]) {
  int n1;
  scanf("%d", &n1);

  gcd(n1);
  return 0;
}
