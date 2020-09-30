#include <stdio.h>

void printTriangleType(int n1, int n2, int n3){
  if(n1 == n2 && n2 == n3){
    printf("equilateral");
    return;
  }

  else if(n1 == n2 || n2 == n3 || n1 == n3){
    printf("isosceles");
    return;
  }
  printf("scalene");

}

int main(int argc, char const *argv[]) {
  int n1;
  int n2;
  int n3;
  scanf("%d", &n1);
  scanf("%d", &n2);
  scanf("%d", &n3);
  printTriangleType(n1, n2, n3);
  return 0;
}
