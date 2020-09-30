#include <stdio.h>

void hasMidPoint(int n1, int n2, int n3){
  int min;
  int max;
  int mid;


  if(n1 > n2 && n1 > n3){
    max = n1;
    if(n2 < n3){
      min = n2;
      mid = n3;
    }

    else{
      min = n3;
      mid = n2;
    }

  }

  else if(n2 > n1 && n2 > n3){
    max = n2;
    if(n1 < n3){
      min = n1;
      mid = n3;
    }
    else{
      min = n3;
      mid = n1;
    }
  }


  else{
    max = n3;
    if(n1 < n2){
      min = n1;
      mid = n2;
    }

    else{
      min = n2;
      mid = n1;
    }
  }

  int correctMid = (max + min)/2;
  if((max + min)%2 !=0){
    printf("false");
    return;
  }

  if(mid == correctMid && min != max && mid != min && mid != max){
    printf("true");
  }

  else{
    printf("false");
  }



}

int main(int argc, char const *argv[]) {
  int n1;
  int n2;
  int n3;
  scanf("%d", &n1);
  scanf("%d", &n2);
  scanf("%d", &n3);
  hasMidPoint(n1, n2, n3);
  return 0;
}
