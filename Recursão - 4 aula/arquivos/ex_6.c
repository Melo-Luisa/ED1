#include "list.c"


//feito no list.c
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
  destroy (l);
  print(l);
  return 0;
}