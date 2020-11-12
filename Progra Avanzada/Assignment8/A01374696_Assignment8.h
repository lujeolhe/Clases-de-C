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
