#include "utils.c"



int missing_number (int *A, int n, int m) {
  /*Terminar*/	
  /*  PRIMEIRA PARTE
  Fazer uma divisão binaria, assim podemos analisar por parte, caso a parte da esquerda <- estiver errada sabemos que é lá; Se não é a parte da direita ->. 
  SEGUNDA PARTE
  achar o menor da seção
  */

  if(A[0] != 0){
    return 0;
  }
  int esquerda = 0;
  int direita = n-1;


  while(esquerda <= direita){
    int meio = (direita + esquerda)/2;
    if(A[meio] == meio){
      esquerda = meio +1;
    }else{
      direita = meio -1;
    }

    return esquerda;
  }


} 

/* */
int main () {
  int i;
  //int n = 4, m = 4;
  //int A[] = {0,1,2,3};
  int n = 4, m = 12;
  int A[] = {4,5,10,11};
  //int n = 7, m = 16;
  //int A[] = {0,1,2,6,9,11,15};
  //int n = 8, m = 16;
  //int A[] = {1,2,3,4,6,9,11,15};
  //int n = 7, m = 7;
  //int A[] = {0,1,2,3,4,5,6};
  //int n = 8, m = 11;
  //int A[] = {0,1,2,3,4,5,6,7,10};
  print (A, n, "Input");
  printf("Missing number: %d\n", missing_number (A, n, m));
  return 0;
}
