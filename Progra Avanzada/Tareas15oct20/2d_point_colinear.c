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
int areColinear(const struct Point2D *pa,const struct Point2D *pb,const struct Point2D *pc);

/////Funcion Principal///////
int main() {
  struct Point2D *pa=newPoint2D();
  struct Point2D *pb=newPoint2D();
  struct Point2D *pc=newPoint2D();
  scanf("%d\n%d",&pa->x,&pa->y );
  scanf("%d\n%d",&pb->x,&pb->y );
  scanf("%d\n%d",&pc->x,&pc->y );


  int q=areColinear((const struct Point2D*)pa,(const struct Point2D*)pb,(const struct Point2D*)pc);
  printf("%d\n",q );

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
int areColinear(const struct Point2D *pa,const struct Point2D *pb,const struct Point2D *pc){

  float a=round(slope(pa,pb)*1000)/1000;
  float b=round(slope(pa,pc)*1000)/1000;
  if(a==b){
    return 1;
  }
  else
   return 0;


}
