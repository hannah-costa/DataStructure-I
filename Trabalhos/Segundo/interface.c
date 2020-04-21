#ifndef interface_c
#define interface_c
#include "collection.h"
#include <stdio.h>

int menu(){
    int opNum = 1;

    printf("What would you like to do?\n\n");
    printf("1) Create a collection (note: you can only have one collection at a time).\n");
    printf("2) Destroy a collection.\n");
    printf("3) Insert a new car into the collection.\n");
    printf("4) Search for a certain car in the collection.\n");
    printf("5) Remove a certain car from the collection.\n");
    printf("6) List every car in the collection.\n");
    printf("Operation number:  ");

    scanf(" %d", &opNum);

    return opNum;
}

void printsCar (Car* car){
    printf("\nBrand:  %s\n", car->brand);
    printf("Number of doors:  %d\n", car->nDoors);
    printf("Power:  %d\n", car->power);
    printf("Price:  $ %.2f\n", car->price);
    printf("License plate:  %ld\n", car->plate);
}

#endif
