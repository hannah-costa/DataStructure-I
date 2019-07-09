#include "functions.h"

int main(void) {

  FILE* fileA = fopen("matrixA.txt", "r");
  FILE* fileB = fopen("matrixB.txt", "r");
  int* dimA = getsDimension(fileA);
  int* dimB = getsDimension(fileB);
  int n = dimA[0], m = dimA[1]; //dimensions of matrix A.
  int p = dimB[0], q = dimB[1]; //dimensions of matrix B.

  float* matA = fReadMat(fileA);
  printf("Matrix A = \n");
  printMatrix(n, m, matA);

  float* matB = fReadMat(fileB);
  printf("Matrix B = \n");
  printMatrix(p, q, matB);
  int opNum;
  char input;
  int stop = false;

  do{

    opNum = Menu();
    //system("clear"); //linux
    system("cls"); //windows
    if (opNum < 1 || opNum > 7){
      printf("Invalid operation number. Please try again.\n");
      continue;
    }

    switch(opNum){
      case 1 :
        multMat(n, m, p, q, matA, matB);
        break;
      case 2 :
        multABT(n, m, p, q, matA, matB);
        break;
      case 3 :
        transpose(n, m, matA);
        break;
      case 4 :
        upperTriangular(n, matA);
        break;
      case 5 :
        mainDiag(n, m, matA);
        break;
      case 6 :
        printsRow(n, m, matA);
        break;
      case 7 :
        printsColumn(n, m, matA);
        break;
      default:
        printf("An error occurred.\n");
        break;
    }
    printf("Continue operations? [Y/N]: ");
    scanf(" %c", &input);
    input = toupper(input);
    while(input != 'Y' && input != 'N'){
      printf("Invalid input. Please enter [Y/N].\n");
      scanf(" %c", &input);
      input = toupper(input);
    }
    if (input ==  'N'){
      stop = true;
    }
  }while(stop == false);
  free(matA);
  free(matB);

  return 0;
}
