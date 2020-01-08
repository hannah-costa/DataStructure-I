/*
Faça um algoritmo que recebe dois números inteiros n e m,
crie dinamicamente uma matriz de floats de tamanho n x m,
lê todos os elementos da matriz e retorna a matriz preenchida.
*/

#include <stdio.h>
#include <stdlib.h>

float** criaEleMatriz (int n, int m){
  float** ma = (float**)malloc(sizeof(float*)*n);

  for (int i=0; i<n; i++){
    ma[i] = (float*)malloc(sizeof(float)*m);
  }
  //lendo os elementos da matriz:
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      scanf("%f", &ma[i][j]);
    }
  }
  return ma;
}
//para teste:
int main(void) {
  float** ma = criaEleMatriz(2, 2);
  
  for (int i=0; i<2; i++){
    for (int j=0; j<2; j++){
      printf("%.2f ", ma[i][j]);
    }
    printf("\n");
  }
  return 0;
}