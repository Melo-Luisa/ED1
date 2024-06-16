#include "queue.h"

Queue* create () {
  return NULL;
}

void destroy (Queue *q) { //list
  // q->next;
  // free(q);

  while (q != NULL) { //enquanto diferente de vazia 
    Queue *t = q->next; //aux passa para o prox
    free(q); //limpa ele
    q = t; //q tem um novo lugar
  }
}

int empty (Queue *q) {
  /*Terminar*/
  // Queue *t = q->next;
  // if(t == NULL)return t;
  return(q == NULL);
  
}

Queue* enqueue (Queue *q, int elem) {
  /*Terminar*/
  /*Cria um elemento (malloc) e insere no final da lista.*/
  Queue *node = (Queue *)malloc(sizeof(Queue));	
  node->data = elem;
  node->next = NULL;
  //return q;  //talvez não precise

  if( q == NULL){
    return node;
  }else{
    Queue *t = q;
    while(t->next != NULL){
      t = t->next;
    }
    t->next = node;
    return q;
  }
}

Queue* dequeue (Queue *q) {
  /*Terminar*/
  /*Remove o elemento (free) do início da lista.*/
  // Queue *t = q;
  // Queue *p = NULL;
     
  // if (t == NULL) { return q; }
  // if (p == NULL) { q = t->next; }
  // else { p->next = t->next; }
  // free (t);
  // return q;

  //ERRO = USAR IF NÃO WHILE

  if(q != NULL) { //enquanto diferente de vazia 
    Queue *t = q->next; //aux passa para o prox
    free(q); //limpa ele
    q = t;
  }
  return q;

  


}

int get_front (Queue *q) {
  /*Terminar*/
  /*Retorna a informação (data) armazenada no início da lista.*/	
  if(!empty(q)){
    return q->data;
  }else{
    return ERROR;
  }

}

void print (Queue *q) {
  /*Terminar*/
  Queue *t;
  printf ("List: ");
  for (t = q; t != NULL; t = t->next)
    printf ("%d ", t->data);
  printf("\n");
}

