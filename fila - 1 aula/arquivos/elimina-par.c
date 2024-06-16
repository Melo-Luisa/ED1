#include "stack.c"

int main () {
  int tam = 6;
  Stack *s = create (tam); // criamo uma fila de 6 casas
  Stack *s2 = create(tam); // cria fila de auxilio, usaremos para eliminar numero pares
  srand(time(NULL));
  int i;
  for (i = 0; i < tam; i++) {
    push (s, i); //adicionamos numero de 5 ao 0 na fila
   
  }
  print (s); // 5 4 3 2 1 0
  

  while(!empty(s)){
    int num = pop(s);
    if((num % 2) == 1){//impar
      push(s2, num);
    }
  }
  
  printf("Segunda Pilha");
  print (s2);
  while(!empty(s2)){
    push(s, pop(s2));
  }
  
  printf("Primeira Pilha - ");
  print(s);

  printf("Segunda Pilha - ");
  print (s2);


  // printf("Primeira Pilha");
  // print (s);

  destroy (s);
  destroy (s2);
  return 0;
}
