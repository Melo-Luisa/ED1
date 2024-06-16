#include "utils.c"

/* */
void bubble_sort_recursive (int *A, int n) {
  /*Terminar*/
  int j;	
  if(n <= 1){
    return;
  }
  for(j = 0;j<n-1;j++){
    if(A[j] > A[j+1]){
      swap(A,j+1,j);
    }
  }
  bubble_sort_recursive(A, n-1);

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
  int n = 10;//toi(argv[1]);;
  //int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
  }  

  start = clock();
  print (A, n, "Input");
  bubble_sort_recursive (A, n);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

