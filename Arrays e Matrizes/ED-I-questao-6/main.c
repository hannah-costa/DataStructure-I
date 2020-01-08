/*
Faça os seguintes algoritmos considerando todas as matrizes
armazenadas em vetor:
  a) recebe a matriz ma(n x m) e retorna a sua transposta;
    float* transposta (int n, int m, float* vma);

  b) recebe duas matrizes ma(n x m) e mb(p x q) e retorna:
  
    b.1) mc = ma x mb^T
      float* multABT (int n, int m, int p, int q, float* vma, float* vmb);
   
    b.2) mc = ma^T x mb
      float* multATB (int n, int m, int p, int q, float* vma, float* vmb);
  
  c) recebe uma matriz ma(n x m) e retorna um vetor com os
     elementos da triangular superior da matriz.
      float* triangularSuperior (int n, float* vma);
    
  d) recebe uma matriz ma(n x n) e retorna true se ela é
     simétrica e false caso contrário.
      int eSimetrica (int n, float* vma);
*/

#include "funcoes.h"
#include "funcoesTeste.h"

int main(void) {
  //seus testes aqui (:
  float* vma = criaMatrizPadrao(3, 3);
  printaMatriz(3, 3, vma);
  printf("\n");
  printf("%d\n", eSimetrica(3, vma));
  
  return 0;
}