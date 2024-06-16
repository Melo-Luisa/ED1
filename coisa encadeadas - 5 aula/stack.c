#include "stack.h"

Stack* create () {
  return NULL;
}

void destroy (Stack *s) {
  while (s != NULL) {
    Stack *t = s->next;
    free(s);
    s = t;
  }	  
  /*Enquanto não vazia, passa para o prox atraves d aux e limpa ele e muda para prox.*/
}

Stack* push (Stack *s, int elem) { 
  /*Terminar*/
  /*Cria um elemento (malloc) e insere no início da lista.*/	
  Stack *node = (Stack *)malloc(sizeof(Stack));
  node->data = elem;
  node->next = s;
  
  return node;
  

  /*Cria um novo local, coloca o elemento no local e passa p prox vazio.*/
}

Stack* pop (Stack *s) {
  /*Terminar*/
  /*Remove o elemento (free) do início da lista.*/	
  if(s != NULL){ //caso não vazio
    Stack *node = s->next;
    free(s);
    s = node;
  }
  return s;
}

int get_peek (Stack *s) {
  /*Terminar*/
  /*Retorna a informação (data) armazenada no início da lista.*/
  if(!empty(s)){
    return s->data;
  }else{
    return ERROR;
  }

}

int empty (Stack *s) {
  /*Terminar*/
  return(s == NULL);
}

void print (Stack *s) {
  /*Terminar*/
  Stack *t;
  printf("Stack (peek): ");
  for (t = s; t != NULL; t = t->next) {
    printf ("%d ", s->data);	  
  }
  printf("\n");
}
