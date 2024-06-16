#include "list.c"

List* merge (List *A, List *B){
  List *t = NULL; //aux
  List *C = NULL;	//cria uma nova lista
  while((A!= NULL) && (B!=NULL)){  //enquanto as listas não estiverem vazias ia rodar
    if(A->data <= B->data){  // se o numero n em A for MENOR que o numero n em B
      if(C == NULL) {  // Se o C estiver vazio e A <B = adiciona numero A na lista C
        C = insert(C, A->data);
        t = C; //inicio
      }else{ // se c não estiver vazia
        t->next = insert(C, A->data); //vai para prox e insere no prox
        t = t->next; //anda mais um
      }
      A = A->next; //vai para prox, como se fosse no for, contador
    }else{ //Caso B < A
      if(C == NULL){ //e C estiver vazio
        C = insert(C, B->data); //adiciona 
        t = C; //t anda d lugar
      }else{ // se o C já estiver casinhas ocupadas
        t->next = insert(C, B->data); //vai p prox e adiciona
        t = t->next; //anda p proc
      }
      B = B->next; //contador
    }
  }
  if(A!=NULL){ //finalzinho feito pelo prof
    t->next = A;
  }else{
    t->next = B;
  }
  return C;
}

/**/
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  printf("Lista A: \n");
  print (A);
  printf("Lista B: \n");
  print (B);
  List *C = merge (A, B);
  printf("\n");
  printf("Lista C: ");
  print (C);
  destroy (C);
  return 0;
}
