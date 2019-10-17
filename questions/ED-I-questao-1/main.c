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
  printf("Digite o tamanho do vetor: ");
  int tam;
  scanf("%d",&tam);

  int v[tam];
  printf("Preencha o vetor:");
  for(int i=0; i<tam; i++){
    scanf("%d",&v[i]);
  }

  printf("Digite a key: ");
  int key;
  scanf("%d",&key);

  int pos = posicaoVetor(v, tam, key);
  if(pos != -1){
    printf("Esta dentro do vetor na posicao %d",pos);
  }else{
    printf("Nao esta dentro do vetor");
  }
  return 0;
}
