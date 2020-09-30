#include <stdio.h>
int gcd(int n1,int n2){
    int aux;
    int result;
    while (n2 != 0){
      aux = n2;
      n2 = n1 % n2;
      n1 = aux;
    }
    result = n1;
    return result;
}

int GCD(int n){
    if(n > 1000000 || n <= 0){
        return 0;
    }

    int total = 0;

    for(int i=1; i<=n; i++){

        if(gcd(n,i)==1){
            total++;
        }

    }
    return total;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d", GCD(n));
    return 0;
}
