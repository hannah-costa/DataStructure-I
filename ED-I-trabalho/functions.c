#include "functions.h"

int* getsDimension (FILE* file){
  /*************************************************************************************|
  | Reads the file and returns an array with the dimensions of the matrix in the file.  |
  | This function doesn't close the file at the end of the function, so it has to be    |
  | used before fReadMat.                                                               |
  |*************************************************************************************/

  if (file == NULL){
    printf("Function getsDimension: there was a problem opening the file.\n");
    return NULL;
  }

  int n, m; //number of rows and columns of matrix
  rewind(file);
  fscanf(file, "%d %d", &n, &m); //reading from the file

  int* dim = (int*)malloc(sizeof(int)*2);
  if (dim == NULL){
    printf("Function getsDimension: there was a problem allocating the array.\n");
    return NULL;
  }

  dim[0] = n;
  dim[1] = m;

  return dim;
}

//reads matrix from a file and creates it
float* fReadMat (FILE* file){
  if (file == NULL){
    printf("Function fReadMat: there was a problem opening the file.\n");
    return NULL;
  }

  int* dim = getsDimension(file);
  if (dim == NULL){
    printf("Function fReadMat: there was a problem allocating the array.\n");
    return NULL;
  }
  int n = dim[0];
  int m = dim[1];

  float* mat = (float*)malloc(sizeof(float)*n*m);
  if (mat == NULL){
    printf("Function fReadMat: there was a problem allocating the matrix.\n");
    return NULL;
  }

  fseek(file, 4, SEEK_SET); //moving file pointer to beginning of matrix in file
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      fscanf(file, "%f", &mat[i*m+j]);
      fseek(file, 1, SEEK_CUR); //moving file pointer to the next number to be read
    }
  }
  
  fclose(file); //closing file, as it will not be needed anymore.
  return mat;
}

//c.1
void multMat (int n, int m, int p, int q, float* matA, float* matB){
  /**********************************************************************|
  |  Multiplies matA by matB. Prints the result of the operation, if     |
  |  it's possible.                                                      |
  |  matA -> n x m                                                       |
  |  matB -> p x q                                                       |
  |  matC -> to exist, m == p. Resulting: n x q                          |
  |  Expected matrix:                                                    |
  |  39 28 26                                                            |
  |  44 17 31                                                            |
  |**********************************************************************/
  
  if (m != p){
    printf("Operation 1: this operation is impossible.\n");
    return;
  }else if(matA == NULL || matB == NULL){
    printf("Operation 1: there was a problem receiving the matrices.\n");
    return;
  }else if(n < 1 || m < 1 || p < 1 || q < 1){
    printf("Operation 1: this operation is impossible.\n");
    return;
  }

  float element = 0;

  printf("A x B =\n");
  
  for(int i=0; i<n; i++){
    for(int j=0; j<q; j++){
      for(int k=0; k<m; k++){
        element += (matA[i*m+k] * matB[k*q+j]);
      }
      printf("%.1f \t", element); 
      element = 0;
    }
    printf("\n");
  }
}

//c.2
void multABT (int n, int m, int p, int q, float* matA, float* matB){
  /*********************************************************************|
  |   Multiplies matrix A by the tranpose of matrix B and prints the    |
  |   resulting matrix, which is n x p, if the operation is possible.   |
  |   The number of columns of the 1st matrix has to be the same as     |
  |   the number of columns of the 2nd matrix.                          |
  |   Expected matrix:                                                  |
  |   37 32 24                                                          |
  |   45 21 26                                                          |
  |*********************************************************************/

  if (m != q){
    printf("Operation 2: this operation is impossible.\n");
    return;
  }else if(matA == NULL || matB == NULL){
    printf("Operation 2: there was a problem receiving the matrices.\n");
    return;
  }else if(n < 1 || m < 1 || p < 1 || q < 1){
    printf("Operation 2: this operation is impossible.\n");
    return;
  }
  float element = 0;

  printf("A x B^T =\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<p; j++){
        for(int k=0; k<m; k++){
          element += matA[i*m+k] * matB[j*p+k];
        }
        printf("%.1f \t", element);
        element = 0;
      }
      printf("\n");
    }
}

//c.3
void transpose (int n, int m, float* mat){ 
  //Receives a matrix, its number of rows and columns and prints its transpose.
  if (mat == NULL){
    printf("Operation 3: there was a problem receiving the matrix.\n");
    return;
  }else if (n < 1 || m < 1){
    printf("Operation 3: this operation is impossible.\n");
    return;
  }

  printf("Transpose:\n");
  for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
      printf("%.1f \t", mat[j*m+i]);
    }
    printf("\n");
  }
}

//c.4
void upperTriangular (int n, float* mat){
  //Prints the elements of the upper triangular of matrix mat. 
  if (mat == NULL){
    printf("Operation 4: there was a problem receiving the matrix.\n");
    return;
  }else if (n < 1){
    printf("Operation 4: there aren't enough elements in the matrix.\n");
    return;
  }

  printf("Upper triangular:\n");
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (j>i){
        printf("%.1f \t", mat[i*n+j]);
      }
    }
  }
}

//c.5
void mainDiag (int n, int m, float* mat){
  //Receives the matrix and prints its main diagonal.
  if (mat == NULL){
    printf("Operation 5: there was a problem receiving the matrix.\n");
    return;
  }else if (n < 1 || m < 1){
    printf("Operation 5: there aren't enough elements in the matrix.\n");
  }

  int nElem = n;
  if (m < n){
    nElem = m;
  }

  printf("Main diagonal:\n");
  for (int i=0; i<nElem; i++){
    printf("%.1f \t", mat[i*m+i]);
  }
}

//c.6
void printsRow (int n, int m, float* mat){
  //Receives the matrix and a specific row to be printed.
  if (mat == NULL){
    printf("Operation 6: there was a problem receiving the matrix.\n");
    return;
  }else if (n < 1 || m < 1){
    printf("Operation 6: there aren't enough elements in the matrix.\n");
    return;
  }
  int k;
  printf("Which row would you like to be printed? ");
  scanf("%d", &k);
  do{
    if (k > n-1 || k < 0){
      printf("Operation 6: the number you entered is invalid. Please try again.\n");
      scanf("%d", &k);
    }
  }while(k > n-1);
  
  printf("Row [%d]:\n", k);
  for (int i=0; i<m; i++){
    printf("%.1f \t", mat[k*m+i]);
  }
}

//c.7
void printsColumn (int n, int m, float* mat){
  //Receives the matrix and a specific row to be printed.
  if (mat == NULL){
    printf("Operation 7: there was a problem receiving the matrix.\n");
    return;
  }else if (n < 1 || m < 1){
    printf("Operation 7: there aren't enough elements in the matrix.\n");
    return;
  }
  int k;
  printf("Which row would you like to be printed? ");
  scanf("%d", &k);
  do{
    if (k > n-1 || k < 0){
      printf("Operation 7: the number you entered is invalid. Please try again.\n");
      scanf("%d", &k);
    }
  }while(k > m-1);

  printf("Column [%d]:\n", k);
  for (int i=0; i<n; i++){
    printf("%.1f \t", mat[i*m+k]);
  }
}

//Test functions:
void printMatrix (int n, int m, float* mat){
  //General function to print a matrix.
  if (mat != NULL){
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        printf("%.1f \t", mat[i*m+j]);
      }
      printf("\n");
    }
  }
  printf("\n");  
}

int Menu(){
  int opNum;
  printf("Please select one of the operations below:\n");
  printf("1. A x B\n\n");
  printf("2. A x B^T\n\n");
  printf("3. A^T\n\n");
  printf("4. Upper triangular of matrix A\n\n");
  printf("5. Main diagonal of matrix A\n\n");
  printf("6. Row from the matrix A\n\n");
  printf("7. Column from the matrix A\n\n");
  printf("Operation number: ");
  scanf(" %d", &opNum);
  return opNum;
}
