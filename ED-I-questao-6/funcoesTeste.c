#include "funcoesTeste.h"

float* criaMatrizPadrao (int n, int m){
  //Função geral pra alocar e criar uma matriz padrão como vetor 
  //para testes. Recebe n (linhas) e m (colunas).
  //O primeiro elemento da matriz criada será k e incrementa de 1 em 1.
  int k = 1;
  float* vma = (float*)malloc(sizeof(float)*n*m);
  if (vma != NULL){
    for (int i=0; i<n*m; i++){
      vma[i] = k;
      k++;
    }
    return vma;
  }
  free(vma);
  return NULL;
}

void printaMatriz (int n, int m, float* vma){
  //Função geral que imprime na tela uma matriz alocada dentro
  //de um vetor para testes.
  if (vma != NULL){
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        printf("%.1f ", vma[i*m+j]);
      }
      printf("\n");
    }
  }  
}