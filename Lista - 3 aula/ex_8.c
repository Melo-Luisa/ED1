#include "list.c"

int copy(List *A, List *B){
  

}
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 0; k < 10; k++) 
    A = insert (A, k);
  print (A);
  

  printf("%d",copy(A, B));
  print (B);
  return 0;
}