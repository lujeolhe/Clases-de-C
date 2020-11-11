#include "A01374696_Assignment8.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double computeEuclidianDissimilarity(const Instance* const i1, const Instance* const i2){
  unsigned int length = i1 -> length;
  double acum = 0;

  //  Validaciones

  for(unsigned int i = 0; i < length ; i++){
    FeatureType* fi1 = ((i1 -> featureTypes) + i);
    FeatureType* fi2 = ((i2 -> featureTypes) + i);


    if(*(fi1) == numerical && *(fi2) == numerical){
      double diferencia = *((i1 -> features) + i) - *((i2 -> features) + i);
      acum += (pow(diferencia, 2));
    }

    else if(*(fi1) == nominal && *(fi2) == nominal){
      double f1 = *((i1 -> features) + i);
      double f2 = *((i2 -> features) + i);
      if(f1 != f2){
        acum += 1;
      }
    }

    else{
      // Validación si uno es numerical y el otro es nominal

    }

  }

  return sqrt(acum);
}

Instance* findNearestNeighbor(const Instance* const arr, const unsigned int length, const Instance* const query, double (*computeDissimilarity) (const Instance* const i1, const Instance* const i2)){
  const Instance* nearestNeighbor = arr;
  double nearestNeighborDistance;
  for(unsigned int i = 0; i < length; i++){
    if(i == 0){
      nearestNeighborDistance = computeDissimilarity(arr, query);
    }

    else{
      const Instance* currentInstance = (arr + i);
      double currentDistance = computeDissimilarity(currentInstance, query);
      if(currentDistance < nearestNeighborDistance){
        nearestNeighbor = currentInstance;
        nearestNeighborDistance = currentDistance;
      }
    }
  }

  return (Instance*)nearestNeighbor;
}

double moda(double* arr, unsigned int length){
  double moda = 0;
  unsigned int repeticiones = 0;
  for(unsigned int i = 0; i < length; i++){
    unsigned int repeticionesAux = 1;
    double aux = *(arr + i);
    for(unsigned int j = i +1; j < length; j++){
      if(*(arr + j) == aux){
        repeticionesAux++;
      }
    }
    if(repeticionesAux >= repeticiones){
      moda = aux;
      repeticiones = repeticionesAux;
    }
  }
  return moda;
}

double media(double* arr, unsigned int length){
  double media = 0;
  for(unsigned int i = 0; i < length; i++){
    media  += *(arr + i);
  }
  media /= length;
  return media;
}

Instance* averageDataset(const Instance* const arr, const unsigned int length){
  Instance* instanciaProm = (Instance*)malloc(sizeof(Instance));
  unsigned const int sizeOfFeatures = arr -> length;
  instanciaProm -> length = sizeOfFeatures;
  instanciaProm -> features = (double*)malloc(sizeof(double) * sizeOfFeatures);
  instanciaProm -> featureTypes = (FeatureType*)malloc(sizeof(FeatureType) * sizeOfFeatures);

  for(unsigned int i = 0; i < sizeOfFeatures; i++){
    // int banderaIgual = 1;
    FeatureType currentFeatureType = *((arr -> featureTypes) + i);
    double arrAux[length];
    arrAux[0] = *((arr -> features) + i);
    for(unsigned int j = 1; j < length; j++){

      if(*(((arr + j) -> featureTypes) + i) != currentFeatureType){
        return NULL;
      }

      if(((arr + j) -> length) != sizeOfFeatures){
        return NULL;
      }

      arrAux[j] = *(((arr + j) -> features) + i);
    }

    if(currentFeatureType == numerical){
      *((instanciaProm -> featureTypes) + i) = numerical;
      *((instanciaProm -> features) + i) = media(arrAux, length);
    }

    else{
      *((instanciaProm -> featureTypes) + i) = nominal;
      *((instanciaProm -> features) + i) = moda(arrAux, length);
    }
  }
  return instanciaProm;
}

int main(int argc, char const *argv[]) {
  double miArr[4] = {2, 2, 3, 3};
  printf("%f\n", media(miArr, 4));
  return 0;
}
