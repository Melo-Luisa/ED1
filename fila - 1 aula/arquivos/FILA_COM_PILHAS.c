#include "stack.h"

void enqueue (Stack *p, int elem) {
  /*Cria um elemento (malloc) e insere no final da lista.*/
    push(p, elem);
 
}

void dequeue (Stack *q) {
  /*Remove o elemento (free) do início da lista.*/
    while(!empty(q)){
        pop(q);
    }


}