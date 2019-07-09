#include "funcoes.h"

float* transposta (int n, int m, float* vma){ 
  //Recebe uma matriz, seu número de linhas e de colunas
  //e retorna sua transposta.
  if (vma != NULL){
    float* vmt = (float*)malloc(sizeof(float)*n*m);

    if (vmt != NULL){
      for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
          vmt[j*n+i] = vma[i*m+j];
        }
      }
      return vmt;
    }
    free(vmt);
  }
  return NULL;
}

float* multABT1 (int n, int m, int p, int q, float* vma, float* vmb){
  //Multiplica a matriz vma pela transposta de vmb e retorna a matriz
  //resultante.
  //O número de colunas da 1ª matriz tem que ser igual ao número de colunas da
  //2ª matriz.
  //Retorna vmt, a matriz resultante.
  //Função que utiliza a função transposta.

  if (m != q || vma == NULL || vmb == NULL){
    printf("Impossível realizar a operação.\n");
    return NULL;
  }else{
    float* vmr = (float*)calloc(n*p,sizeof(float));

    if (vmr == NULL){
      return NULL;
    }

    float* vmt = transposta(p, q, vmb);
    
    if (vmt == NULL){
      free(vmr);
      return NULL;
    }

    for (int i=0; i<n; i++){
      for (int j=0; j<p; j++){
        for (int k=0; k<m; k++){
          vmr[i*p+j] += vma[i*m+k] * vmt[k*p+j];
        }
      }
    }
    return vmr;
  }
}

float* multABT2 (int n, int m, int p, int q, float* vma, float* vmb){
  //Multiplica a matriz vma pela transposta de vmb e retorna a matriz
  //resultante.
  //O número de colunas da 1ª matriz tem que ser igual ao número de colunas da
  //2ª matriz.
  //Retorna vmt, a matriz resultante.
  //Função que não utiliza a função transposta.

  if (m != q || vma == NULL || vmb == NULL){
    printf("Impossível realizar a operação.\n");
    return NULL;
  }else{
    float* vmr = (float*)calloc(n*p,sizeof(float));

    if (vmr == NULL){
      return NULL;
    }

    for (int i=0; i<n; i++){
      for (int j=0; j<p; j++){
        for (int k=0; k<m; k++){
          vmr[i*p+j] += vma[i*m+k] * vmb[j*n+k];
        }
      }
    }
    return vmr;
  }
}

float* multATB1 (int n, int m, int p, int q, float* vma, float* vmb){
  //Multiplica a matriz transposta de vma pela matriz vmb e retorna a matriz
  //resultante.
  //O número de linhas da 1ª matriz tem que ser igual ao número de linhas da
  //2ª matriz.
  //Retorna vmt, a matriz resultante.
  //Função que utiliza a função transposta.

  if (n != p || vma == NULL || vmb == NULL){
    printf("Impossível realizar a operação.\n");
    return NULL;
  }else{
    float* vmr = (float*)calloc(m*q,sizeof(float));

    if (vmr == NULL){
      return NULL;
    }

    float* vmt = transposta(n, m, vma);
    
    if (vmt == NULL){
      free(vmr);
      return NULL;
    }

    for (int i=0; i<m; i++){
      for (int j=0; j<q; j++){
        for (int k=0; k<n; k++){
          vmr[i*q+j] += vmt[i*n+k] * vmb[k*q+j];
        }
      }
    }
    return vmr;
  }
}

float* multATB2 (int n, int m, int p, int q, float* vma, float* vmb){
  //Multiplica a matriz transposta de vma pela matriz vmb e retorna a matriz
  //resultante.
  //O número de linhas da 1ª matriz tem que ser igual ao número de linhas da
  //2ª matriz.
  //Retorna vmt, a matriz resultante.
  //Função que não utiliza a função transposta.

  if (n != p || vma == NULL || vmb == NULL){
    printf("Impossível realizar a operação.\n");
    return NULL;
  }else{
    float* vmr = (float*)calloc(m*q,sizeof(float));

    if (vmr == NULL){
      return NULL;
    }

    for (int i=0; i<m; i++){
      for (int j=0; j<q; j++){
        for (int k=0; k<n; k++){
          vmr[i*q+j] += vma[k*m+i] * vmb[k*q+j];
        }
      }
    }
    return vmr;
  }
}

float* triangularSuperior (int n, float* vma){
  //Retorna um vetor com os elementos triangulares superiores da
  //matriz vma. 
  if (vma == NULL){
    return NULL;
  }
  int t = 0; //número de elementos da triangular superior.
  int k = 0; //variável para iterar dentro do vetTriang.
  for (int i=1; i<=n; i++){
    t += i-1;
  }

  float* vetTriang = (float*)malloc(sizeof(float)*t);
  if (vetTriang == NULL){
    return NULL;
  }
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (j>i){
        vetTriang[k] = vma[i*n+j];
        k++;
      }
    }
  }
  return vetTriang;
}

int eSimetrica (int n, float* vma){
  //Retorna 0 se a matriz vma(quadrada) não for simétrica e 1 se for.
  if (vma == NULL){
    return -1;
  }

  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (vma[i*n+j] != vma[j*n+i]){
        return 0;
      }
    }
  }
  return 1;
}