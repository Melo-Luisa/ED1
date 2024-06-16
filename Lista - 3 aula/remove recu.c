#include "list.c"

/*Qual o tamanho da lista?*/

List* sumir(List* l, int num) {
  if (l == NULL) 
    return NULL;

  if (l->data == num) { 
    List *temp =   l->next;  // adiciona em um outro nó o proximo elemento 
    free(l); // some com o l
    return sumir(temp, num); // faz com que vá para prox, o return necessário para que volte com os numeros selecionados
    
  } else {
    l->next =  sumir(l->next, num); // se não for o numero selecionado vai p proximo e chama função dnv
    //return l;
  }
}
int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 10; k++) 
    l = insert (l, k);
  for (k = 1; k >= 5; k--) 
    l = insert (l, k);

  print (l);

  l = sumir(l, 1);
  l = sumir(l, 10);
  l = sumir(l, 5);

   print (l);
  return 0;
}