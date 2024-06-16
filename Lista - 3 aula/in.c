#include "list.c"

/* Se o elemento está no meio*/
int in (List *l, int k) { // k = 5
  List *t;
  for(t = l; t != NULL; t = t->next){
    if(t->data == k){ 
      return TRUE;
    }
    // já posso para ai para que não verifique os proximos
  }
}

/* */
int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = insert (l, k);
  for (k = 9; k >= 5; k--) 
    l = insert (l, k);

  print (l);

  printf("Pertence %d = %d\n", 5, in(l, 5));
  printf("Pertence %d = %d\n", -1, in(l, -1));
  destroy (l);
  return 0;
}
