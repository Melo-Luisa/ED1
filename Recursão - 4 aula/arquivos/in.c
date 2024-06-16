#include "list.c"
#include <limits.h>

/* */
int in (List *l, int k) {
  /*IN de forma recursiva.*/

  if(l != NULL){
    if(k == l->data){
      return TRUE; // se for igual ok
    }else{
      return in(l->next,k); // se não for roda dnv
    }
    
  }else{
    return FALSE; // se for vazio significa q não achou e dale 0;
  }	
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 0; k <= 5; k++) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("In = %d\n", in(l,3));
  printf("In = %d\n", in(l,6));
  destroy (l);
  return 0;
}
