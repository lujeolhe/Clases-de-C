////////Bibliotecas///////
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

///////Estructuras////////
struct Point2D{
int x;
int y;
};

/////Prototipos de Funciones////////
int quadrant(const struct Point2D *pa);

/////Funcion Principal///////
int main() {
  struct Point2D pa;
  scanf("%d\n%d",&pa.x,&pa.y );

  int q=quadrant((const struct Point2D*)&pa);
  printf("%d\n",q );


}

////Definicion de Funciones////////
int quadrant(const struct Point2D *pa){
  int q=0;
  if (pa->x==0||pa->y==0){
    return q;
  }
  else{
    int xaux=pa->x/fabs(pa->x), yaux=2*(pa->y/fabs(pa->y));
    switch (xaux+yaux) {
      case 1: return 2;
      case -1: return 3;
      case 3: return 1;
      case -3: return 4;
      default: return -1;
    }
  }
}
