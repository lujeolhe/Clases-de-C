typedef enum{
  Ending,
  Bifurcation,
  Unknown
}MinutiaType;

typedef struct Minutia{
  unsigned short int x;
  unsigned short int y;
  float angle;
  MinutiaType type;

}Minutia;

typedef struct MinutiaArray{
  Minutia* minutiae;
  unsigned short length;
}MinutiaArray;

Minutia* createMinutia(unsigned short int x, unsigned short int y, float angle, MinutiaType type);
MinutiaArray* createMinutiaArray(const unsigned short length);
void releaseMinutiaArray(MinutiaArray* minutiae);
double loloFunction(const Minutia* minutia1, const Minutia* minutia2);
Minutia* findCentroid(const MinutiaArray* const minutiaArray);
int testFindCentroid();
