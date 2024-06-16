#include "list.c"

/* */
int size (List *l) {
  int cont = 0;
  if(l != NULL){
    cont = 1 + size(l->next);
    /*Até que seja vazio, soma um e vai p proximo somando mais 1;*/
  }
  return cont;
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Size = %d\n", size(l));
  destroy (l);
  return 0;
}


