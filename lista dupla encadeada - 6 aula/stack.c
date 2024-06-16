#include "stack.h"

Stack* create (){
    return NULL;
};
void destroy (Stack *s){
    if(s!=NULL){
        Stack *t = s->next;
        free(s);
        s = t;
    }
};   
 /*inserir elemento*/ 
Stack* push (Stack *s, int elem){
    Stack *node = (Stack *)malloc(sizeof(Stack));
    node->data = elem;
    node->next = s;
    node->prev = NULL;
    if (s != NULL) 
        s->prev= node;
    return node;
}
    

/*retirar o elemento  ERRADO*/
Stack* pop (Stack *s){
    if (s != NULL) {
        Stack *tmp = s;
        if (s->next != NULL)
            s->next->prev = NULL;
            s = s->next;
            free(tmp);
        return s;
    }
};

/*primeiro elemento da lista*/
int get_peek (Stack *s){
    if(s != NULL)
    return s->data;
    else return ERROR;

};
int empty (Stack *s){
    return (s==NULL);
};
void print (Stack *s);