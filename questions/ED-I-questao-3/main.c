#include <stdio.h>
#include <stdlib.h>

float** multMat (int n, int m, int p, int q, float** ma, float** mb){
  // ma -> n x m
  //mb -> p x q
  //mc -> para existir, m == p. Resultante: n x q
  if (m != p){
    return NULL;
  }else{
    int a = n, b = q; //dimensões da matriz resultante
    int c = m; //quantas vezes o 3o laço será repetido -> m==p
    float** mc = (float**)malloc(sizeof(float*)*a);

    for (int i=0; i<a; i++){
      mc[i] = (float*)malloc(sizeof(float)*b);
    }

    for(int i=0; i<a; i++){
      for(int j=0; j<b; j++){
        for(int k=0; k<c; k++){
            mc[i][j] += ma[i][k] * mb[k][j];
        }
      }
    }
    return mc;
  }
}
//para teste:
int main(void) {
  /*
  ma:
  1 2 3
  4 5 6

  mb:
  8 7
  6 5
  4 3

  retorno esperado:
  32  26
  86  71
  */
  int k = 1, l = 8;
  float** ma = (float**)malloc(sizeof(float*)*2);
  float** mb = (float**)malloc(sizeof(float*)*3);

  for (int i=0; i<2; i++){
    ma[i] = (float*)malloc(sizeof(float)*3);
  }
  for (int i=0; i<3; i++){
    mb[i] = (float*)malloc(sizeof(float)*2);
  }
  for (int i=0; i<2; i++){
    for (int j=0; j<3; j++){
      ma[i][j] = k;
      k++;
    }
  }
  for (int i=0; i<3; i++){
    for (int j=0; j<2; j++){
      mb[i][j] = l;
      l--;
    }
  }
  float** mc = multMat(2, 3, 3, 2, ma, mb);
  for (int i=0; i<2; i++){
    for (int j=0; j<2; j++){
      printf("%.2f ", mc[i][j]);
    }
    printf("\n");
  }

  return 0;
}