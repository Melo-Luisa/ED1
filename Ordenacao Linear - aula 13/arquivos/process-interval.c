#include "utils.c"

/* */
int* process_interval (int *A, int n, int range) {
  int i;
  int *C = (int *)malloc((range+1) * sizeof(int)); /*contador*/
  /*Terminar*/
  //int *C = (int *)malloc((range + 1) * sizeof(int)); // Array de contagem
  int *P = (int *)malloc((range + 1) * sizeof(int)); // Array de prefixo
  if (!C || !P) {
      printf("Memória insuficiente.\n");
      exit(1);
  }

  // Inicializar o array de contagem
  for (i = 0; i <= range; i++) {
      C[i] = 0;
  }

  // Contar a frequência de cada número em A
  for (int i = 0; i < n; i++) {
      C[A[i]]++;
  }

  // Construir o array de prefixo
  P[0] = C[0];
  for (int i = 1; i <= range; i++) {
      P[i] = P[i - 1] + C[i];
  }

  free(C); // Liberar o array de contagem, já que não é mais necessário
  return P; // Retornar o array de prefixo

}

int query (int *C, int n, int i, int j) {
  /*Terminar*/
  /*Não pode ter laço de repetição!*/
  if (i == 0) {
      return C[j];
  } else {
      return C[j] - C[i - 1];
  }

}

/* */
int main () {
  int a, b, n = 15;
  int range = 10;
  int A[] = {9,2,0,8,7,9,3,2,0,7,5,0,2,6,0};
  print (A, n, "Input");
  int *C = process_interval (A, n, range);
  a = 0, b = 3;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 4, b = 8;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 0, b = 0;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 6, b = 6;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 2, b = 4;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  a = 9, b = 9;
  printf("Consulta: qtd elems no intervalo [%d - %d] = %d\n", a, b, query(C,n,a,b));
  return 0;
}

