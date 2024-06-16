#include "utils.c"

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


int quick_find (int *A, int left, int right, int k) {
  /*Terminar*/	
  if(left < right){
    int p;
    p = partition(A,left, right);
    quick_find(A, left, p-1,k);
    quick_find(A, p+1, right,k);
    if(p == k){
      return A[p];
    }
  }	
  
}

/* */
int main () {
  int n = 8;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
  print (A, n, "Input");
  int elem = quick_find (A, 0, n-1, 4);
  printf("%d\n", elem);
  print (A, n, "Partial sorted");
  
  return 0;
}
