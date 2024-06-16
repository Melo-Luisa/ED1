#include "list.c"

/*Qual o tamanho da lista?*/

int size(List *l){
  int cont = 0;
  List *t;
  for(t = l; t!=NULL; t= t->next){
    cont+= 1;
  }
  printf("Essa Lista contem: %d elementos.\n", cont);
  //return cont;
}

int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = insert (l, k);
  for (k = 9; k >= 5; k--) 
    l = insert (l, k);

  print (l);

  size(l);
  return 0;
}