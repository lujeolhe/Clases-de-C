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
struct Point2D *newPoint2D();
float slope(const struct Point2D *pa,const struct Point2D *pb);

/////Funcion Principal///////
int main() {
  struct Point2D *pa=newPoint2D();
  struct Point2D *pb=newPoint2D();
  scanf("%d\n%d",&pa->x,&pa->y );
  scanf("%d\n%d",&pb->x,&pb->y );


  float q=slope((const struct Point2D*)pa,(const struct Point2D*)pb);
  printf("%.2f\n",q );

  free(pa);
  free(pb);

}

////Definicion de Funciones////////
struct Point2D *newPoint2D(){
  struct Point2D *nuevoPunto2D=(struct Point2D *)malloc(sizeof(struct Point2D));
  return nuevoPunto2D;
}
float slope(const struct Point2D *pa,const struct Point2D *pb){
  float a= pa->y-pb->y;
  float b= pa->x-pb->x;
  float res=a/b;

  return res;
}
