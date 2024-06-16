#include "utils.c"

/*
Não utiliza array extra (O), Ele parece com um merge-sort pois trabalha com metades mas o seu modo d comparação é diferente
Eu diria pior, foi esse intercala se assemelha ao insert-sort, sendo O(n^2), e o merge-sort sendo O(nlogn) */
/*Função para intercalar*/
void merge (int A[], int l, int m, int r) {
  /*Terminar*/	
   while (m <= r) { 
        int c = A[m], i; 
        for (i = m-1; (i >= l) && (A[i] > c); i--) 
            A[i+1] = A[i]; 
        A[i+1] = c; 
        m++; 
    }

}
/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r) {
  if (l < r) {
    int m = (l + r)/2;
    merge_sort (A, l, m);
    merge_sort (A, m+1, r); 
    merge (A, l, m, r);
  }
}

/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

