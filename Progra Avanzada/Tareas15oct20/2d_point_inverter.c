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
struct Point2D swapAndNegate(const struct Point2D *pa);

/////Funcion Principal///////
int main() {
  struct Point2D pa;
  scanf("%d\n%d",&pa.x,&pa.y );

  struct Point2D q=swapAndNegate((const struct Point2D*)&pa);
  printf("%d\n%d\n",q.x,q.y );

}

////Definicion de Funciones////////
struct Point2D swapAndNegate(const struct Point2D *pa){
  int x=pa->x,y=pa->y;
  struct Point2D res={-(y/fabs(y))*fabs(y),-x/fabs(x)*fabs(x)};
  return res;
}
