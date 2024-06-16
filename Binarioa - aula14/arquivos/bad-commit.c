#include "utils.c"

int busca_binaria_recursiva(int *A, int esquerda, int direita) {
  if (direita >= esquerda) {
    int meio = esquerda + direita  / 2;

    // se o primeiro for meio E se ele é o indice 0 OU o anterior for zero, então será o primeiro erro encontrada
    if (A[meio] == 1 && (meio == 0 || A[meio - 1] == 0))
      return meio;

    // se meio for 1, temos que ver se p esquerda não tem mais 
    if (A[meio] == 1)
      return busca_binaria_recursiva(A, esquerda, meio - 1);
    // se não for esquerda, poderá ser direita 
    return busca_binaria_recursiva(A, meio + 1, direita);
  }

  return -1;

}

/* */
int bad_commit (int *A, int n) {

  /*Terminar*/	
 return busca_binaria_recursiva(A, 0, n-1);

} 

/* */
int main () {
  int n = 7;
  int A[] = {0,1,1,1,1,1,1};
  printf("Bad commit: %d\n", bad_commit(A, n));
  return 0;
}
