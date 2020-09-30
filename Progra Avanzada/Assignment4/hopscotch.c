#include <stdio.h>

void hopscotch(int n){
    int top = 1;
    int bottom = 3 * n + top;

    while(top <= bottom){
        if(top % 3 == 1){
            printf("   %d\n", top);
        }
        else if(top % 3 == 0){
            printf("     %d\n", top);
        }
        else{
            printf("%d", top);
        }
        top++;
    }
}

int main(int argc, char** _argv){
    int n;
    scanf("%d",&n);
    hopscotch(n);
    return 0;
}
