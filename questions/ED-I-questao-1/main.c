#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
//include all libraries at once used in competitive programming
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
