#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "A01374696_Test2.h"

Minutia* createMinutia(unsigned short int x, unsigned short int y, float angle, MinutiaType type){
  Minutia* minutia = (Minutia*)malloc(sizeof(Minutia));
  minutia -> x = x;
  minutia -> y = y;
  minutia -> type = type;
  minutia -> angle = angle;
  return minutia;
}

MinutiaArray* createMinutiaArray(const unsigned short length){
  MinutiaArray* minutiaArray = (MinutiaArray*)malloc(sizeof(MinutiaArray));
  minutiaArray -> length = length;
  minutiaArray -> minutiae = (Minutia*)malloc(sizeof(Minutia) * length);
  for(unsigned int i = 0; i < length; i++){
    ((minutiaArray -> minutiae) + i) -> x = 0;
    ((minutiaArray -> minutiae) + i) -> y = 0;
    ((minutiaArray -> minutiae) + i) -> angle = 0;

    ((minutiaArray -> minutiae) + i) -> type = (MinutiaType)0;
  }
  return minutiaArray;
}

void releaseMinutiaArray(MinutiaArray* minutiae){
  free(minutiae -> minutiae);
  free(minutiae);
}

Minutia* findCentroid(const MinutiaArray* const minutiaArray, double (*computeDistance) (const Minutia* const m1, const Minutia* const m2)){
  double distanciaAcum = 9999999999;
  double distanciaAcum2 = 0;
  Minutia* centroid = minutiaArray -> minutiae;
  for(unsigned short i = 0; i < minutiaArray -> length; i++){
    for(unsigned short j = 0; j < minutiaArray -> length; j++){
      distanciaAcum2 += computeDistance((minutiaArray->minutiae) + i, (minutiaArray->minutiae) + j);
    }
    if(distanciaAcum2 < distanciaAcum){
      distanciaAcum = distanciaAcum2;
      centroid = (minutiaArray -> minutiae) + i;
    }

    distanciaAcum2 = 0;

  }
  return centroid;
}

double loloFunction(const Minutia* minutia1, const Minutia* minutia2){
  int x1 = minutia1 -> x;
  int y1 = minutia1 -> y;
  int x2 = minutia2 -> x;
  int y2 = minutia2 -> y;
  double xx = pow(x2 - x1, 2);
  double yy = pow(y2 - y1, 2);
  return sqrt(xx + yy);
}

int testFindCentroid(){
  MinutiaArray* minutiaArray = createMinutiaArray(10);
  // (2, 2)
  ((minutiaArray -> minutiae) + 0) -> x = 2;
  ((minutiaArray -> minutiae) + 0) -> y = 2;
  ((minutiaArray -> minutiae) + 0) -> type = Bifurcation;
  ((minutiaArray -> minutiae) + 0) -> angle = 30;

  // (5, 2)
  ((minutiaArray -> minutiae) + 1) -> x = 5;
  ((minutiaArray -> minutiae) + 1) -> y = 2;
  ((minutiaArray -> minutiae) + 1) -> type = Ending;
  ((minutiaArray -> minutiae) + 1) -> angle = 90;

  // (2, 5)
  ((minutiaArray -> minutiae) + 2) -> x = 2;
  ((minutiaArray -> minutiae) + 2) -> y = 5;
  ((minutiaArray -> minutiae) + 2) -> type = Unknown;
  ((minutiaArray -> minutiae) + 2) -> angle = 180;

  // (3, 5)
  ((minutiaArray -> minutiae) + 3) -> x = 3;
  ((minutiaArray -> minutiae) + 3) -> y = 5;
  ((minutiaArray -> minutiae) + 3) -> type = Ending;
  ((minutiaArray -> minutiae) + 3) -> angle = 70;


  //4,5
  ((minutiaArray -> minutiae) + 4) -> x = 4;
  ((minutiaArray -> minutiae) + 4) -> y = 5;
  ((minutiaArray -> minutiae) + 4) -> type = Unknown;
  ((minutiaArray -> minutiae) + 4) -> angle = 20;

  //5,5
  ((minutiaArray -> minutiae) + 5) -> x = 5;
  ((minutiaArray -> minutiae) + 5) -> y = 5;
  ((minutiaArray -> minutiae) + 5) -> type = Ending;
  ((minutiaArray -> minutiae) + 5) -> angle = 90;

  //5,3
  ((minutiaArray -> minutiae) + 6) -> x = 5;
  ((minutiaArray -> minutiae) + 6) -> y = 3;
  ((minutiaArray -> minutiae) + 6) -> type = Ending;
  ((minutiaArray -> minutiae) + 6) -> angle = 300;

  //2,3
  ((minutiaArray -> minutiae) + 7) -> x = 2;
  ((minutiaArray -> minutiae) + 7) -> y = 3;
  ((minutiaArray -> minutiae) + 7) -> type = Bifurcation;
  ((minutiaArray -> minutiae) + 7) -> angle = 190;

  //3,3 CENTROID
  ((minutiaArray -> minutiae) + 8) -> x = 3;
  ((minutiaArray -> minutiae) + 8) -> y = 3;
  ((minutiaArray -> minutiae) + 8) -> type = Unknown;
  ((minutiaArray -> minutiae) + 8) -> angle = 227;

  //5,4
  ((minutiaArray -> minutiae) + 9) -> x = 5;
  ((minutiaArray -> minutiae) + 9) -> y = 4;
  ((minutiaArray -> minutiae) + 9) -> type = Unknown;
  ((minutiaArray -> minutiae) + 9) -> angle = 135;

  Minutia* centroid = ((minutiaArray -> minutiae) + 8);
  if(centroid == findCentroid(minutiaArray, loloFunction)){
    releaseMinutiaArray(minutiaArray);
    return 1;
  }

  releaseMinutiaArray(minutiaArray);
  return 0;
}

double calcularDistanciaAcumulada(MinutiaArray *array, unsigned short index){
  Minutia* minutia = ((array -> minutiae) + index);
  unsigned short length = array -> length;
  double distanciaAcum = 0;
  for(unsigned short i = 0; i < length; i++){
    distanciaAcum += loloFunction(minutia, ((array -> minutiae) + i));
  }
  return distanciaAcum;
}


MinutiaArray *sortMinutiaArray(MinutiaArray *original){
  MinutiaArray* array = createMinutiaArray(original -> length);
  array -> length = original -> length;
  array -> minutiae = original -> minutiae;

  short length = array -> length;
  for(short i = 0; i < length - 1; i++){
    for(short j = 0; j < length-i-1; j++){
      double distancia1 = calcularDistanciaAcumulada(array, j);
      double distancia2 = calcularDistanciaAcumulada(array, j + 1);
      short aux = j + 1;
      if(distancia1 > distancia2){
        Minutia* greater = ((array -> minutiae) + j);
        short gX = greater -> x;
        short gY = greater -> y;
        float gAngle =greater -> angle;
        MinutiaType gType = greater -> type;

        Minutia* lower =  ((array -> minutiae) + aux);
        short lX = lower -> x;
        short lY = lower -> y;
        float lAngle = lower -> angle;
        MinutiaType lType = lower -> type;


        ((array -> minutiae) + j) -> x = lX;
        ((array -> minutiae) + j) -> y = lY;
        ((array -> minutiae) + j) -> angle = lAngle;
        ((array -> minutiae) + j) -> type = lType;

        ((array -> minutiae) + aux) -> x = gX;
        ((array -> minutiae) + aux) -> y =  gY;
        ((array -> minutiae) + aux) -> angle = gAngle;
        ((array -> minutiae) + aux) -> type = gType;

      }
    }
  }
  return array;
}

int testSort(){
  MinutiaArray* minutiaArray = createMinutiaArray(10);
  // (2, 2)
  ((minutiaArray -> minutiae) + 0) -> x = 2;
  ((minutiaArray -> minutiae) + 0) -> y = 2;
  ((minutiaArray -> minutiae) + 0) -> type = Bifurcation;
  ((minutiaArray -> minutiae) + 0) -> angle = 30;

  // (5, 2)
  ((minutiaArray -> minutiae) + 1) -> x = 5;
  ((minutiaArray -> minutiae) + 1) -> y = 2;
  ((minutiaArray -> minutiae) + 1) -> type = Ending;
  ((minutiaArray -> minutiae) + 1) -> angle = 90;

  // (2, 5)
  ((minutiaArray -> minutiae) + 2) -> x = 2;
  ((minutiaArray -> minutiae) + 2) -> y = 5;
  ((minutiaArray -> minutiae) + 2) -> type = Unknown;
  ((minutiaArray -> minutiae) + 2) -> angle = 180;

  // (3, 5)
  ((minutiaArray -> minutiae) + 3) -> x = 3;
  ((minutiaArray -> minutiae) + 3) -> y = 5;
  ((minutiaArray -> minutiae) + 3) -> type = Ending;
  ((minutiaArray -> minutiae) + 3) -> angle = 70;


  //4,5
  ((minutiaArray -> minutiae) + 4) -> x = 4;
  ((minutiaArray -> minutiae) + 4) -> y = 5;
  ((minutiaArray -> minutiae) + 4) -> type = Unknown;
  ((minutiaArray -> minutiae) + 4) -> angle = 20;

  //5,5
  ((minutiaArray -> minutiae) + 5) -> x = 5;
  ((minutiaArray -> minutiae) + 5) -> y = 5;
  ((minutiaArray -> minutiae) + 5) -> type = Ending;
  ((minutiaArray -> minutiae) + 5) -> angle = 90;

  //5,3
  ((minutiaArray -> minutiae) + 6) -> x = 5;
  ((minutiaArray -> minutiae) + 6) -> y = 3;
  ((minutiaArray -> minutiae) + 6) -> type = Ending;
  ((minutiaArray -> minutiae) + 6) -> angle = 300;

  //2,3
  ((minutiaArray -> minutiae) + 7) -> x = 2;
  ((minutiaArray -> minutiae) + 7) -> y = 3;
  ((minutiaArray -> minutiae) + 7) -> type = Bifurcation;
  ((minutiaArray -> minutiae) + 7) -> angle = 190;

  //3,3 CENTROID
  ((minutiaArray -> minutiae) + 8) -> x = 3;
  ((minutiaArray -> minutiae) + 8) -> y = 3;
  ((minutiaArray -> minutiae) + 8) -> type = Unknown;
  ((minutiaArray -> minutiae) + 8) -> angle = 227;

  //5,4
  ((minutiaArray -> minutiae) + 9) -> x = 5;
  ((minutiaArray -> minutiae) + 9) -> y = 4;
  ((minutiaArray -> minutiae) + 9) -> type = Unknown;
  ((minutiaArray -> minutiae) + 9) -> angle = 135;

  MinutiaArray *sorted = sortMinutiaArray(minutiaArray);
  for(short i = 0; i < sorted -> length; i++){
    printf("%d, %d\n", ((sorted -> minutiae) + i) -> x, ((sorted -> minutiae) + i) -> y);
  }

  releaseMinutiaArray(minutiaArray);
  releaseMinutiaArray(sorted);

  return 0;
}

int main(int argc, char const *argv[]) {
  testSort();
  return 0;
}
