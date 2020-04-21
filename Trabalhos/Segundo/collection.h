#ifndef collection_h
#define collection_h

typedef struct _collection_
{
    int maxElms; //max number of elements in the collection.
    int nElms; //current number of elements in the collection.
    int cur; //current element of the array.
    void** elms; //the array with the elements of the collection.
}Col;

typedef struct _car_
{
    char brand[20];
    int nDoors;
    int power;
    float price;
    long int plate;
}Car;

#ifdef collection_c
int cmpCar(void* kBrand, void* kPlate, void* elm);
int cmpBrand(void* kBrand, void* elm);
int cmpPlate(void* kPlate, void* elm);
void printStatus (Col* c);
Col* colCreate(int n);
int colInsert(Col* c, void* elm);
void* colQuery(Col* c, void* keyBrand, void* keyPlate);
void* colRemoveSpec(Col* c, void* keyBrand, void* keyPlate);
int colDestroy(Col* c);

#else
extern int cmpCar(void* kBrand, void* kPlate, void* elm);
extern int cmpBrand(void* kBrand, void* elm);
extern int cmpPlate(void* kPlate, void* elm);
extern void printStatus (Col* c);
extern Col* colCreate(int n);
extern int colInsert(Col* c, void* elm);
extern void* colQuery(Col* c, void* keyBrand, void* keyPlate);
extern void* colRemoveSpec(Col* c, void* keyBrand, void* keyPlate);
extern int colDestroy(Col* c);
#endif
#endif
