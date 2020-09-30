#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n1;
  int n2;
  int n3;
  scanf("%d", &n1);
  scanf("%d", &n2);
  scanf("%d", &n3);

  if(n1 < n2 && n1 < n3){
    printf("%d", n1);
  }

  else if(n2 < n1 && n2 < n3){
    printf("%d", n2);
  }

  else{
    printf("%d", n3);
  }
}
