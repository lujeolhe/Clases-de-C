typedef enum FeatureType{
  numerical,
  nominal
}FeatureType;

typedef struct Instance{
  double* features;
  FeatureType* featureTypes;
  unsigned int length;
}Instance;

double computeEuclidianDissimilarity(const Instance* const i1, const Instance* const i2);
Instance* findNearestNeighbor(const Instance* const arr, const unsigned int length, const Instance* const query, double (*computeDissimilarity) (const Instance* const i1, const Instance* const i2));
Instance* averageDataset(const Instance* const arr, const unsigned int length);
double moda(double* arr, unsigned int length);
double media(double* arr, unsigned int length);
int testComputeEuclidianDissimilarity1();
int testComputeEuclidianDissimilarity2();
int testComputeEuclidianDissimilarity3();
int testComputeEuclidianDissimilarity4();
int testFindNearestNeighbor1();
int testAverageDataset1();
int testAverageDataset2();
int testAverageDataset3();
int testAverageDataset4();
Instance* createInstance(int length);
void freeInstance(Instance* instance);
