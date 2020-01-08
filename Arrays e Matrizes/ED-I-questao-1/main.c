/*
Faça uma função que recebe um vetor de inteiros v,
um número n, e um valor inteiro key, e retorna -1
se key não está no vetor ou a posição no vetor onde
está key.
*/

#include <stdio.h>
#include <stdlib.h>

//sendo n o tamanho do vetor
int posicaoVetor (int v[], int n, int key){
  for(int i=0; i<n; i++){
    if(v[i] == key){
      return i;
    }
  }
  return -1;
}
//teste:
int main() {
  int v[5] = {0, 5, 16, 43, 7};
  printf("%d\n", posicaoVetor(v, 5, 12));
  return 0;
}
