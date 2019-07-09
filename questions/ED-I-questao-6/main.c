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