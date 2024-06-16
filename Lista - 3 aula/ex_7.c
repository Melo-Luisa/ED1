#include "list.c"
/*Se as listas são iguais*/

int similar(List *A, List* B){
    List* ta, *tb;
    ta = A;
    tb = B;
    while(ta!=NULL && tb!=NULL){
        if(ta->data != tb->data){
          return FALSE;
        }else{
          return TRUE;
        }
        ta = ta->next;
        tb = tb->next;
    }
}


int main () {
  int k;
List *A = NULL, *B = NULL;
  for (k = 0; k <=4; k++) 
    A = insert (A, k);
  for (k = 9; k >=5; k--) 
    B = insert (B, k);

  print (A);
  print (B);

  printf("%d",similar(A, B));
  return 0;
}