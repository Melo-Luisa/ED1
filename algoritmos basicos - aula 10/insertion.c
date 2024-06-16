#include "utils.c"


/*  Funciona*/
void insertion_sort (int *A, int n) {	
  int chave, i,j;
  for(i=1; i<n;i++){
    chave = A[i];
    j = i-1;
    while( j >= 0 && A[j]>chave){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = chave;
  }
}

/* */
int main () {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  // if (argc < 2) {
  //   printf("run: %s [size]\n", argv[0]);
  //   exit(1);
  // }
   
  int i;
  int n = 10;//atoi(argv[1]);
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
  }  

  start = clock();
  print (A, n, "Input");
  insertion_sort (A, n);
  print (A, n, "Sorted");
  //print_array(A, n);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

