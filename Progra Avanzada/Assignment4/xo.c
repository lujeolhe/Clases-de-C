#include <stdio.h>

void xo(int n){

    for(int i=0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i-j == 0 || i + j == n-1)
            {
                printf("x");
            }else
            {
                printf("o");
            }
        }
        printf("\n");
    }
}

int main() {
  int n;
  scanf("%d", &n);
  xo(n);
}
