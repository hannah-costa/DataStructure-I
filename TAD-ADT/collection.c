#ifndef collection_c
#define collection_c
#include "collection.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct _collection_{
	int max; //max number of elements in the collection.
	int nElms; //current number of elements in the collection.
	int cur; //current element of the array.
	void** elms; //the array with the elements of the collection.
}Col;

int cmp(void* a, void* b){
	int* ia; int* ib;
	ia = (int*) a;
	ib = (int*) b;
	if (*ia == *ib){
		return true;
	}else{
		return false;
	}
}

Col* colCreate(int n){
	//creates the collection with n elements.
	Col* c;
	if (n > 0){
		c = (Col*)malloc(sizeof(Col));
		if (c != NULL){
			c->elms = (void**)malloc(sizeof(void*)*n);
			if (c->elms != NULL){
				c->max = n;
				c->nElms = 0;
				c->cur = -1;
				return c;
			}
			free(c);
		}
	}
	return NULL;
}

int colInsert(Col* c, void* elm){
	//inserts an element into the collection.
	if (c->nElms < c->max){
		c->elms[c->nElms] = elm;
		c->nElms++;
		return true;
	}
	return false;
}

void* colQuery(Col* c, void* key, int (*cmp)(void*, void*)){
	//Checks if the key element is in the collection. Returns the element
	//if it has been found or NULL if not.

	void* aux;
	int i;
	int stat; //has the value returned by the function cmp.

	if (c != NULL){
		if (c->nElms > 0){
			i = 0;
			stat = cmp(key, c->elms[i]);
			while (stat != true && i < c->nElms){
				i++;
				stat = cmp(key, c->elms[i]);
			}
			if (key == c->elms[i]){
				aux = c->elms[i];
				return aux;
			}
		}
	}
	return NULL;
}

void* colGetFirst(Col* c){
	//Returns the first element of the array in the collection.
	if (c != NULL){
		c->cur = 0;
		return c->elms[c->cur];
	}
	return NULL;
}

void* colGetNext(Col* c){
	//Returns the next element of the array in the collection.
	if (c != NULL){
		if (c->nElms > 0){
			c->cur++;
			if (c->cur++ > c->nElms){
				return c->elms[c->cur];
			}
		}
	}
	return NULL;
}

void* colRemoveLast(Col* c){
	//Removes last element of the collection and returns it.
	void* elm;
	if (c != NULL){
		if (c->nElms > 0){
			elm = c->elms[c->nElms-1];
			c->nElms--;
			return elm;
		}
	}
	return NULL;
}

void* colRemoveFirst(Col* c){
	//Removes first element of the collection and returns it.
	void* elm;
	if (c != NULL){
		if (c->nElms > 0){
			elm = c->elms[0];
			c->nElms--;
			for (int i=0; i < c->nElms; i++){
				c->elms[i] = c->elms[i+1];
			}
		}
	}
	return elm;
}

void* colRemoveSpec(Col* c, void* key, int (*cmp)(void*, void*)){
	//Checks if a specific element (key) is in the array of the collection, removes and returns
	//it if it's been found.

	void* aux;
	int i;
	int stat; //has the value returned by the function cmp.

	if (c != NULL){
		if (c->nElms > 0){
			i = 0;
			stat = cmp(key, c->elms[i]);
			while (stat != true && i < c->nElms){
				i++;
				stat = cmp(key, c->elms[i]);
			}
			if (stat == true){
				aux = c->elms[i];
				c->nElms--;
				while (i < c->nElms){
					c->elms[i] = c->elms[i+1];
					i++;
				}
				return aux;
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