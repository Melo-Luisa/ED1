#include "list.c"

/*Qual o maior numero da lista?*/

int max(List*l){
  int maior = -INT_MAX;
  if(l == NULL)//nunca esquecer dessa parada
    return maior;
  else{
    int max_prox = max(l->next);
    if(l->data > max_prox)
      maior = l->data;
    else
      maior = max_prox;
  }  
  return maior;
}

int main () {
  int k;
  List *l = NULL;
  for (k = 5; k <= 4; k++) 
    l = insert (l, k);
  for (k = 9; k >= 5; k--) 
    l = insert (l, k);

  print (l);

  //max(l);
  printf("%d", max(l));
  return 0;
}


 //List *menor;
    // for(t=l; t!=NULL; t=t->next){
    //     if(t->data >= maior){ // 5 > 0
    //         maior = t->data;
    //     }
    //return maior;
        
    // }