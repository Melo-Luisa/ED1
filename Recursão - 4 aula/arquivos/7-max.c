#include "list.c"


int max(List *l){

}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 0; k <= 10; k++) {
    l = insert_back (l, k);
  }

  printf("Lista = ");
  print (l);
  printf("\n");
  max(l);
  destroy (l);
  
  return 0;
}