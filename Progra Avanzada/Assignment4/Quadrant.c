#include <stdio.h>

void quadrant(float n1, float n2){
  if(n1 == 0 || n2 == 0){
    printf("0");
    return;
  }

  if(n1 > 0 && n2 >0){
    printf("1");
    return;
  }

  if(n1 < 0 && n2 > 0){
    printf("2");
    return;
  }

  if(n1 >0 && n2 < 0){
    printf("4");
    return;
  }

  if(n1 < 0 && n2 < 0){
    printf("3");
    return;
  }

}

int main(int argc, char const *argv[]) {
  float n1;
  float n2;
  scanf("%f", &n1);
  scanf("%f", &n2);
  quadrant(n1, n2);
  return 0;
}
