#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int* getsDimension (FILE* file);
float* fReadMat (FILE* file);
void multMat (int n, int m, int p, int q, float* matA, float* matB);
void multABT (int n, int m, int p, int q, float* matA, float* matB);
void transpose (int n, int m, float* mat);
void upperTriangular (int n, float* mat);
void mainDiag (int n, int m, float* mat);
void printsRow (int n, int m, float* mat);
void printsColumn (int n, int m, float* mat);
void printMatrix (int n, int m, float* mat);
int Menu();