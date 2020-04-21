#ifndef collection_c
#define collection_c
#include "collection.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int cmpBrand(void* kBrand, void* elm){
        //auxiliar function used to check if the car brand is the same as the 
        //searched.
    char* sBrand = (char*)kBrand;
    Car* cElm = (Car*)elm;

    if (strcmp(sBrand, cElm->brand) == 0){
        return true;
    }else{
        return false;
    }
}


int cmpPlate(void* kPlate, void* elm){
        //auxiliar function used to check if the car license plate is the same as 
        //the searched.
    long int sPlate = (long int)kPlate;
    Car* cElm = (Car*)elm;

    if (sPlate == cElm->plate){
        return true;
    }else{
        return false;
    }
}

void printStatus (Col* c){
        //just a function to print the current status of the collection.
    printf("\nMax number of elements: %d \nNumber of elements: %d \n", c->maxElms, c->nElms);
}

Col* colCreate(int n){
    //creates the collection with n elements.
    Col* c;
    if (n > 0){
        c = (Col*)malloc(sizeof(Col));
        if (c != NULL){
            c->elms = (void**)malloc(sizeof(void*)*n);
            if (c->elms != NULL){
                c->maxElms = n;
                c->nElms = 0;
                c->cur = -1;
                return c;
            }else{
                free(c);
            }
        }
    }
    return NULL;
}

int colInsert(Col* c, void* elm){
    //inserts an element into the collection.
    if (c != NULL){
        if (c->nElms < c->maxElms){
            c->elms[c->nElms] = elm;
            c->nElms++;
            return true;
        }
    }
    return false;
}

void* colQuery(Col* c, void* keyBrand, void* keyPlate){
    //Checks if the key element is in the collection. Returns the element
    //if it has been found or NULL if not.

    void* aux;
    int statBrand; //has the value returned by the function cmp.
    int statPlate;

    if (c != NULL){
        if (c->nElms > 0){
            for (int i=0; i<c->nElms; i++){
                statBrand = cmpBrand(keyBrand, c->elms[i]);
                statPlate = cmpPlate(keyPlate, c->elms[i]);
                if (statBrand == true && statPlate == true){
                    aux = c->elms[i];
                    return aux;
                }
            }
        }
    }
    return NULL;
}

void* colRemoveSpec(Col* c, void* keyBrand, void* keyPlate){
    //Checks if a specific element (key) is in the array of the collection, removes and returns
    //it if it's been found.

    void* aux;
    int statBrand; //has the value returned by the function cmp.
    int statPlate;

    if (c != NULL){
        if (c->nElms > 0){
            for (int i=0; i<c->nElms; i++){
                statBrand = cmpBrand(keyBrand, c->elms[i]);
                statPlate = cmpPlate(keyPlate, c->elms[i]);
                if (statBrand == true && statPlate == true){
                    aux = c->elms[i];
                    c->nElms--;
                    for (int j=i; j < c->nElms; j++){
                        c->elms[j] = c->elms[j+1];
                    }
                    return aux;
                }
            }
        }
    }
    return NULL;
}

int colDestroy(Col* c){
    //Destroys the collection. Returns true if the operation was successful or false if not.
    if (c != NULL){
        if (c->nElms == 0){
            free(c->elms);
            free(c);
            return true;
        }
    }
    return false;
}

#endif
