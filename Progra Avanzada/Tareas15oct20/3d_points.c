////////Bibliotecas///////
#include <stdio.h>
#include <math.h>
#include<stdlib.h>

///////Estructuras////////
struct Point3D{
int x;
int y;
int z;
};

/////Prototipos de Funciones////////
struct Point3D *newPoint3D();
float distance3D(const struct Point3D *pa,const struct Point3D *pb);

/////Funcion Principal///////
int main() {
  struct Point3D *pa=newPoint3D();
  struct Point3D *pb=newPoint3D();
  scanf("%d\n%d\n%d",&pa->x,&pa->y,&pa->z );
  scanf("%d\n%d\n%d",&pb->x,&pb->y,&pb->z );

  float distance=distance3D((const struct Point3D*)pa,(const struct Point3D*)pb);
  printf("%.2f\n",distance );
  
  free(pa);
  free(pb);


}

////Definicion de Funciones////////
struct Point3D *newPoint3D(){
  struct Point3D *nuevoPunto3D=(struct Point3D *)malloc(sizeof(struct Point3D));
  return nuevoPunto3D;
}
float distance3D(const struct Point3D *pa,const struct Point3D *pb){
  float distance=sqrt(pow(pa->x-pb->x,2)+pow(pa->y-pb->y,2)+pow(pa->z-pb->z,2));
  return distance;
}
