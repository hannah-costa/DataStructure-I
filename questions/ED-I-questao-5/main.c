#include <stdio.h>
#include <stdlib.h>

float* retornaLinha (int n, int m, float** ma, int k){
  float* linha = (float*)malloc(sizeof(float)*m);
  for (int i=0; i<m; i++){
    linha[i] = ma[k][i];
  }
  return linha;
}

float* retornaColuna (int n, int m, float** ma, int k){
  float* coluna = (float*)malloc(sizeof(float)*n);
  for (int i=0; i<n; i++){
    coluna[i] = ma[i][k];
  }
  return coluna;
}

float retornaSomaEmColK (int n, int m, float** ma, int k){
  float soma = 0;
  for (int i=0; i<n; i++){
    soma += ma[i][k];
  }
  return soma;
}

float retornaSomaEmLinhaK (int n, int m, float** ma, int k){
  float soma = 0;
  for (int i=0; i<m; i++){
    soma += ma[k][i];
  }
  return soma;
}

int main(void) {
  /*
  ma:
  1 2 3
  4 5 6

  retorno esperado para retornaLinha (k = 1): {4, 5, 6} 
  retorno esperado para retornaColuna (k = 2): {3, 6} 
  retorno esperado para retornaSomaEmColK (k = 2): 9
  retorno esperado para retornaSomaEmLinhaK (k = 1): 15 
  */
  int k = 1;
  float** ma = (float**)malloc(sizeof(float*)*2);

  for (int i=0; i<2; i++){
    ma[i] = (float*)malloc(sizeof(float)*3);
  }
  for (int i=0; i<2; i++){
    for (int j=0; j<3; j++){
      ma[i][j] = k;
      k++;
    }
  }

  //teste retornaLinha
  float* linha = retornaLinha(2, 3, ma, 1);
  printf("retornaLinha:\n");
  for (int i=0; i<3; i++){
    printf("%.1f ", linha[i]);
  }
  printf("\n");

  //teste retornaColuna
  float* coluna = retornaColuna(2, 3, ma, 2);
  printf("retornaColuna:\n");
  for (int i=0; i<2; i++){
    printf("%.1f ", coluna[i]);
  }
  printf("\n");

  //teste retornaSomaEmColK
  float somaEmCol = retornaSomaEmColK(2, 3, ma, 2);
  printf("retornaSomaEmColK:\n");
  printf("%.1f\n", somaEmCol);

  //teste retornaSomaEmLinhaK
  float somaEmLinha = retornaSomaEmLinhaK(2, 3, ma, 1);
  printf("retornaSomaEmLinhaK:\n");
  printf("%.1f\n", somaEmLinha);

  return 0;
}