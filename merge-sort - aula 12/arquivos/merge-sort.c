#include "utils.c"

/*Função para intercalar dois subvetores em um conjunto ordenado. 
 *{A} é o vetor de entrada, {l} é a esquerda (de left), 
 {m} é o meio (ou middle), {r} é a direita (de right),
 {O} é o vetor auxilar (de output). */

/*Respostas: 
n = 10; t = 0.00s
n = 100; t = 0.00s
n = 1000; t = 0.00s;
n = 10000; t = 0.00s
n = 100000; t = 0.03s
n = 1000000; t = 0.21s
n = 10000000; t = 2.33s*/

/*
n = 10; t = 0.00s
n = 100; t = 0.00s
n = 1000; t = 0.00s;
n = 10000; t = 0.00s
n = 1m t = 0.10s
n = 10m t = 1.16*/

/*
n = 10; t = 0.00s
n = 100; t = 0.00s
n = 1000; t = 0.00s;
n = 10000; t = 0.00s
n = 1m t = 0.01
n = 10m t = 0.19 */

/*
n = 10; t = 0.00s
n = 100; t = 0.00s
n = 1000; t = 0.00s;
n = 10000; t = 0.00s
n = 1m t = 0.01
n = 10m t = 0.13*/
void merge (int A[], int esquerda, int m, int direita, int O[]) {
  /*Terminar*/

  int i = esquerda;
  int j = m +1;
  int k = esquerda;

  while(i <= m && j <= direita){
    if(A[i] <= A[j]){
      O[k++] = A[i++];
      
    }else{
      O[k++] = A[j++];
    }
  }
  	
  while(j <= direita){
    O[k++] = A[j++];
  }
  while(i<=m){
    O[k++] = A[i++];
  }
  
  for(int i = esquerda; i <= direita; i++){
    A[i] = O[i];
  }
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int esquerda, int direita, int O[]) {
  /*Terminar*/
  if(esquerda < direita){
    int m = ((esquerda+direita)/2);
    merge_sort(A, esquerda, m, O);
    merge_sort(A, m+1,direita,O);
    merge(A,esquerda,m,direita, O);
  }	
}

/* */
int main () {
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  /*if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }*/
  int i;
  //int n = atoi(argv[1]);
  int n = 1000000; /*teste com 100, 1K, 10K, 1M, 10M*/
  int *A = (int *)malloc(n * sizeof(int));
  int *O = (int *)malloc(n * sizeof(int)); /*array auxiliar*/
  for (i = 0; i < n; i++) {
    //A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i;   /*valores em ordem crescente*/
    //A[i] = n-i; /*valores em ordem descrescente*/
    A[i] = 0;   /*valores iguais*/
  }
  start = clock();
  //print (A, n, "Input");
  merge_sort (A, 0, n-1, O);
  //print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  free (O);
  return 0;
}

