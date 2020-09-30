#include <stdio.h>

void season(int n1, int n2){
  if(n1 == 12 || (n1>=1 && n1 <= 3)){
    if(n1 != 3){

      if(n1 == 12 && n2 < 16){
        printf("Fall");
        return;
      }

      printf("Winter");
      return;
    }

    else{
      if(n2 <= 15){
        printf("Winter");
      }
      else{printf("Spring");}

      return;
    }
  }

if(n1 >= 3 && n1 <= 6){
  if(n1 == 6 && n2 >= 16){
    printf("Summer");
    return;
  }

  else{
    printf("Spring");
    return;
  }
}

if(n1 >= 6 && n1 <= 9){
  if(n1 == 9 && n2 < 16){
    printf("Summer");
    return;
  }

  else{
    if(n1 !=9){
      printf("Summer");
      return;
    }

    printf("Fall");
    return;

  }
}

  if(n1 == 12 && n2 >= 16){
    printf("Winter");
    return;
  }

  printf("Fall");
  return;



}

int main(int argc, char const *argv[]) {
  int n1;
  int n2;

  scanf("%d", &n1);
  scanf("%d", &n2);

  season(n1, n2);
  return 0;
}
