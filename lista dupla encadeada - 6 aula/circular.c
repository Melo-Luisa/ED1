#include "list.c"

List* create_circular (List *l) {
  /*Terminar!*/	
  List *t = l;
  while(t->next != NULL){
    t = t->next;
  }
  t->next = l;
  return l;
  /*Erros arrumados: Estava atribuindo o valor de t a l dentro do while e não estava fazendo o t andar*/
}

int main () {
  int i;	
  int n = 3;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  //print (l);
  l = create_circular(l);
  print (l);
  destroy (l);
  return 0;
} 
