/*
Faça um algoritmo que recebe dois inteiros n e m 
e uma matriz ma (n x m) e retorna um vetor com os
elementos da diagonal principal de ma.
*/

#include <stdio.h>
#include <stdlib.h>

float* diagPrin (int n, int m, float** ma){
  int nElem; //número de elementos da diagonal principal

  if (n >= m){
    nElem = m;
  }else if(m > n){
    nElem = n;
  }

  float* diag = (float*)malloc(sizeof(float)*nElem);

  for (int i=0; i<nElem; i++){
    diag[i] = ma[i][i];
  }
  return diag;
}

int main(void) {
  /*
  Matriz exemplo (ma): 4 x 3
  0   6   12
  18  24  30
  36  42  48
  54  60  66
  retorno esperado: v[3] = {0, 24, 48};
  */
  int k = 0;
  float** ma = (float**)malloc(sizeof(float*)*4);
  
  for (int i=0; i<4; i++){
    ma[i] = (float*)malloc(sizeof(float)*3);
  }

  for (int i=0; i<4; i++){
    for (int j=0; j<3; j++){
      ma[i][j] = k;
      k += 6;
    }
  }
  float* diag = diagPrin(4, 3, ma);

  for (int i=0; i<3; i++){
    printf("%.1f ", diag[i]);
  }
  return 0;
}