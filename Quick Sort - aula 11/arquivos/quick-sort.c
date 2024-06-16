#include "utils.c"

//RESPOSTA
/*
n = tempo

Aleatorio 
10 = 0.00s
100 = 0.00s
1.000 = 0.01s
10.000 = 0.02s
100.000 = 0.27s
1.000.000 = 10.43s

crescente
10 = 0.00
100 = 0.00
1.000 = 0.00
10.000 = 

iguais 
100 = 0.00
1.000 = 0.01
10.000 = 0.29
100.000=

*/


/* */
int partition (int A[], int left, int right) {
  /*Terminar*/	
  int pivo, i, j;
  pivo = A[right];
  i = left - 1;
  for(j = left; j <= right-1; j++){
    if( A[j] <= pivo){
      i = i + 1;
      swap(A, i, j);
    }
    
  }
  swap(A,i+1,right);
  return i+1;
}

/* */
void quick_sort (int *A, int left, int right) {
  /*Terminar*/
  if(left < right){
    int p;
    p = partition(A,left, right);
    quick_sort(A, left, p-1);
    quick_sort(A, p+1, right);
  }	
}

/* */
int main () {
// int argc, char *argv[]
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;
  int n = 10; /*Altere para 100, 1000, 10 mil, 1 milhao elementos!*/
  //int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
    //A[i] = 0; /*iguais*/
  }  

  start = clock();
  print (A, n, "Input");
  quick_sort (A, 0, n-1);
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

