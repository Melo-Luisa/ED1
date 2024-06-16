#include "list.c"

/* */
int sum (List *l) {
  int cont = 0;
  /*Terminar.*/	
  if (l != NULL){
    cont+= l->data + sum(l->next); 
    /*Dentro do contador, pegar o numero da vem e conta com o proximo até que seja vazio - funciona*/
  }

  // if(l != NULL){
  //   l->next = sum(l->next);
  // }else{
  //   cont += l->data;
  // }
  /*Até o l for vazio vai p prox e armaze a soma dele, quando chega no ultimo vai p else e acumula o q? - NÃO FUNCIONA*/
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
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
