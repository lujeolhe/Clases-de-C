#include <stdio.h>

int digitRange(int n){
    if(n < 0){
      n = n * -1;
    }
    int max = n % 10;
    int min = n % 10;
    while(n > 0){
        int aux = n % 10;
        if (aux > max)
        {
            max = aux;
        }

        else if(aux < min){
            min = aux;
        }

    n /= 10;

    }

    int resultado = (max-min) + 1;
    return resultado;

}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", digitRange(n));
}
