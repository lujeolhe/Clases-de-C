#include "A01374696_Assignment8.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void freeInstance(Instance* instance){
  free(instance -> features);
  free(instance -> featureTypes);
  free(instance);
}

double computeEuclidianDissimilarity(const Instance* const i1, const Instance* const i2){
  unsigned int length = i1 -> length;
  double acum = 0;

  //  Validaciones
  if(i1->length == 0 || i2 -> length == 0){
    return -1;
  }

  if(i1 -> length != i2 -> length){
    return -2;
  }


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
      return -3;
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
  if(arr == NULL){
    printf("arr es NULL ");
    return NULL;
  }
  Instance* instanciaProm = (Instance*)malloc(sizeof(Instance));
  unsigned const int sizeOfFeatures = arr -> length;
  instanciaProm -> length = sizeOfFeatures;
  instanciaProm -> features = (double*)malloc(sizeof(double) * sizeOfFeatures);
  instanciaProm -> featureTypes = (FeatureType*)malloc(sizeof(FeatureType) * sizeOfFeatures);

  for(unsigned int i = 0; i < sizeOfFeatures; i++){
    FeatureType currentFeatureType = *((arr -> featureTypes) + i);
    double arrAux[length];
    arrAux[0] = *((arr -> features) + i);
    for(unsigned int j = 1; j < length; j++){

      if(*(((arr + j) -> featureTypes) + i) != currentFeatureType){
        freeInstance(instanciaProm);
        printf("Feauture No Corresponde ");
        return NULL;
      }

      if(((arr + j) -> length) != sizeOfFeatures){
        freeInstance(instanciaProm);
        printf("Tamaños Diferentes ");
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

Instance* createInstance(int length){
  Instance* instance = (Instance*)malloc(sizeof(Instance));
  instance -> length = length;
  instance -> features = (double*)malloc(sizeof(double)*length);
  instance -> featureTypes = (FeatureType*)malloc(sizeof(FeatureType)*length);
  return instance;
}
int testComputeEuclidianDissimilarity1(){
  Instance* i1 = createInstance(0);
  Instance* i2 = createInstance(5);
  for (unsigned int i = 0; i < 5; i++) {
    *((i2 -> features) + i) = i;
    *((i2 -> featureTypes) + i) = numerical;
  }

  double res = computeEuclidianDissimilarity(i1, i2);
  freeInstance(i1);
  freeInstance(i2);
  if(res == -1){
    return 1;
  }
  return 0;
}

int testComputeEuclidianDissimilarity2(){
  Instance* i1 = createInstance(4);
  Instance* i2 = createInstance(5);
  for (unsigned int i = 0; i < 5; i++) {
    if(i < 4){
      *((i1 -> features) + i) = i;
      *((i1 -> featureTypes) + i) = numerical;
    }
    *((i2 -> features) + i) = i;
    *((i2 -> featureTypes) + i) = numerical;
  }

  double res = computeEuclidianDissimilarity(i1, i2);
  freeInstance(i1);
  freeInstance(i2);
  if(res == -2){
    return 1;
  }

  return 0;
}

int testComputeEuclidianDissimilarity3(){
  Instance* i1 = createInstance(5);
  Instance* i2 = createInstance(5);
  for (unsigned int i = 0; i < 5; i++) {
    *((i1 -> features) + i) = i * i;
    *((i1 -> featureTypes) + i) = numerical;
    *((i2 -> features) + i) = i;
    *((i2 -> featureTypes) + i) = nominal;
  }

  double res = computeEuclidianDissimilarity(i1, i2);
  freeInstance(i1);
  freeInstance(i2);
  if(res == -3){
    return 1;
  }

  return 0;
}

int testComputeEuclidianDissimilarity4(){
  Instance* i1 = createInstance(5);
  Instance* i2 = createInstance(5);
  for (unsigned int i = 0; i < 5; i++) {
    *((i1 -> features) + i) = i * i;
    *((i2 -> features) + i) = i;

    if(i <= 1){
      *((i2 -> featureTypes) + i) = nominal;
      *((i1 -> featureTypes) + i) = nominal;
    }

    else{
       *((i2 -> featureTypes) + i) = numerical;
       *((i1 -> featureTypes) + i) = numerical;
    }
  }

  double res = computeEuclidianDissimilarity(i1, i2);
  freeInstance(i1);
  freeInstance(i2);
  if(res == sqrt(184)){
    return 1;
  }
  return 0;

}

int testFindNearestNeighbor1(){

  Instance* arr = (Instance*)malloc(sizeof(Instance)*4);
  for(unsigned int i = 0; i < 4; i++){
    (arr + i) -> features = (double*)malloc(sizeof(double)* 4);
    (arr + i) -> featureTypes = (FeatureType*)malloc(sizeof(FeatureType)* 4);
    (arr + i) -> length = 4;
  }

  Instance* query = createInstance(4);

  for (unsigned int i = 0; i < 4; i++) {
    *(((arr) -> features) + i) = i * i;
    *(((arr + 1) -> features) + i) = i;
    *(((arr + 2) -> features) + i) = i + i;
    *(((arr + 3) -> features) + i) = i + 2;
    *((query -> features) + i) = i * i;

    if(i <= 1){
      *((arr -> featureTypes) + i) = nominal;
      *(((arr + 1) -> featureTypes) + i) = nominal;
      *(((arr + 2) -> featureTypes) + i) = nominal;
      *(((arr + 3) -> featureTypes) + i) = nominal;
      *((query -> featureTypes) + i) = nominal;
    }

    else{
       *((arr -> featureTypes) + i) = numerical;
       *(((arr + 1) -> featureTypes) + i) = numerical;
       *(((arr + 2) -> featureTypes) + i) = numerical;
       *(((arr + 3) -> featureTypes) + i) = numerical;
       *((query -> featureTypes) + i) = numerical;
    }

  }

  int valorRetorno = 0;

  Instance* nearestNeighbor = findNearestNeighbor(arr, 4, query, computeEuclidianDissimilarity);
  if(nearestNeighbor == arr){
    valorRetorno = 1;
  }

  else{valorRetorno = 0;}

  for(unsigned int i = 0; i < 4; i++){
    free((arr + i) -> features);
    free((arr + i) -> featureTypes);
  }
  free(arr);
  freeInstance(query);

  return valorRetorno;
}

int testAverageDataset1(){
  Instance* arr = NULL;
  if(averageDataset(arr, 0) == NULL){
    return 1;
  }
  return 0;
}

int testAverageDataset2(){
  Instance* arr = (Instance*)malloc(sizeof(Instance)*4);
  for(unsigned int i = 0; i < 4; i++){
    if(i == 3){
      (arr + i) -> features = (double*)malloc(sizeof(double)* 5);
      (arr + i) -> featureTypes = (FeatureType*)malloc(sizeof(FeatureType)* 5);
      (arr + i) -> length = 5;
    }
    else{
    (arr + i) -> features = (double*)malloc(sizeof(double)* 4);
    (arr + i) -> featureTypes = (FeatureType*)malloc(sizeof(FeatureType)* 4);
    (arr + i) -> length = 4;}
  }



  for (unsigned int i = 0; i < 4; i++) {
    *(((arr) -> features) + i) = i * i;
    *(((arr + 1) -> features) + i) = i;
    *(((arr + 2) -> features) + i) = i + i;
    *(((arr + 3) -> features) + i) = i + 2;

    if(i <= 1){
      *((arr -> featureTypes) + i) = nominal;
      *(((arr + 1) -> featureTypes) + i) = nominal;
      *(((arr + 2) -> featureTypes) + i) = nominal;
      *(((arr + 3) -> featureTypes) + i) = nominal;
    }

    else{
       *((arr -> featureTypes) + i) = numerical;
       *(((arr + 1) -> featureTypes) + i) = numerical;
       *(((arr + 2) -> featureTypes) + i) = numerical;
       *(((arr + 3) -> featureTypes) + i) = numerical;
    }
  }
  *(((arr + 3) -> features) + 3) = 30;
  *(((arr + 3) -> featureTypes) + 3) = nominal;
  int valorRetorno = 0;
  if(averageDataset(arr, 4) == NULL){
    valorRetorno = 1;
  }

  else{
    valorRetorno = 0;
  }

  for(unsigned int i = 0; i < 4; i++){
    free((arr + i) -> features);
    free((arr + i) -> featureTypes);
  }
  free(arr);

  return valorRetorno;

}

int testAverageDataset3(){
  Instance* arr = (Instance*)malloc(sizeof(Instance)*4);
  for(unsigned int i = 0; i < 4; i++){
    (arr + i) -> features = (double*)malloc(sizeof(double)* 4);
    (arr + i) -> featureTypes = (FeatureType*)malloc(sizeof(FeatureType)* 4);
    (arr + i) -> length = 4;
  }



  for (unsigned int i = 0; i < 4; i++) {
    *(((arr) -> features) + i) = i * i;
    *(((arr + 1) -> features) + i) = i;
    *(((arr + 2) -> features) + i) = i + i;
    *(((arr + 3) -> features) + i) = i + 2;

    if(i <= 1){
      *((arr -> featureTypes) + i) = nominal;
      *(((arr + 1) -> featureTypes) + i) = nominal;
      *(((arr + 2) -> featureTypes) + i) = nominal;
      *(((arr + 3) -> featureTypes) + i) = nominal;
    }

    else{
       *((arr -> featureTypes) + i) = numerical;
       *(((arr + 1) -> featureTypes) + i) = numerical;
       *(((arr + 2) -> featureTypes) + i) = numerical;
       *(((arr + 3) -> featureTypes) + i) = numerical;
    }
  }

  *(((arr + 3) -> featureTypes) + 2) = nominal;

  int valorRetorno = 0;
  if(averageDataset(arr, 4) == NULL){
    valorRetorno = 1;
  }

  else{
    valorRetorno = 0;
  }

  for(unsigned int i = 0; i < 4; i++){
    free((arr + i) -> features);
    free((arr + i) -> featureTypes);
  }
  free(arr);

  return valorRetorno;
}

int testAverageDataset4(){
  Instance* arr = (Instance*)malloc(sizeof(Instance)*4);
  for(unsigned int i = 0; i < 4; i++){
    (arr + i) -> features = (double*)malloc(sizeof(double)* 4);
    (arr + i) -> featureTypes = (FeatureType*)malloc(sizeof(FeatureType)* 4);
    (arr + i) -> length = 4;
  }



  for (unsigned int i = 0; i < 4; i++) {
    *(((arr) -> features) + i) = i * i;
    *(((arr + 1) -> features) + i) = i;
    *(((arr + 2) -> features) + i) = i + i;
    *(((arr + 3) -> features) + i) = i + 2;

    if(i <= 1){
      *((arr -> featureTypes) + i) = nominal;
      *(((arr + 1) -> featureTypes) + i) = nominal;
      *(((arr + 2) -> featureTypes) + i) = nominal;
      *(((arr + 3) -> featureTypes) + i) = nominal;
    }

    else{
       *((arr -> featureTypes) + i) = numerical;
       *(((arr + 1) -> featureTypes) + i) = numerical;
       *(((arr + 2) -> featureTypes) + i) = numerical;
       *(((arr + 3) -> featureTypes) + i) = numerical;
    }
  }


  int valorRetorno = 0;

  Instance* instanciaProm = averageDataset(arr, 4);
  double e1 = *((instanciaProm -> features));
  double e2 = *((instanciaProm -> features) + 1);
  double e3 = *((instanciaProm -> features) + 2);
  double e4 = *((instanciaProm -> features) + 3);


  for(unsigned int i = 0; i < 4; i++){
    free((arr + i) -> features);
    free((arr + i) -> featureTypes);
  }
  free(arr);

  if((e1 == 0 && e2 == 1) && (e3 == 3.5 && e4 == 5.75)){
    valorRetorno = 1;
  }

  return valorRetorno;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", testAverageDataset4());
}
