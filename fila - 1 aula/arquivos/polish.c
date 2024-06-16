#include "stack.c"


int operador(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

//necessário fazer por prioridade
void reversed_polish_notation (char *c) {
  Stack *n1 = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') { //enquanto não estiver vazio
    if(c[i] == '(') {
      push(n1,c[i]); //adiciona
    }else if(c[i] >= '0' && c[i] <= '9'){ // numeros
      printf("%c ", c[i]);
      // adicionei os numeros
    }else if(c[i] == ')'){ // caso feche parenteses
      while(!empty(n1) && get_peek(n1) != '(' ){ //caso não vazia e o primeiro seja diferente de (
        printf("%c ", pop(n1));
      }
      if(!empty(n1) && get_peek(n1) == '('){ //se for igual ele tira
        pop(n1);
      }
    }else if(c[i] == '+' || c[i] == '-' || c[i] == '*'|| c[i] == '/'){ //caso seja operadores
      while(!empty(n1) && operador(get_peek(n1)) >= operador(c[i])){ //caso não for vazio 
        printf("%c ", pop(n1));
      }
      push(n1, c[i]);

    }  
    i++;    
  }

  while (!empty(n1)) { //caso não esteja vazia, significa que não há numeros
    printf("%c ", pop(n1));
  }
  printf("\n");
  destroy(n1);
}

//9 0 1 + 2 3 * * + 
void compute_polish_expression(char *c){
  Stack *n1 = create(strlen(c));
  
  //int soma, menos, multi, div;
  int i = 0;
  while (c[i] != '\0') { //até que não seja vazio
    if(c[i] >= '0' && c[i] <= '9'){ //Caso seja numero
      push(n1,c[i]-'0'); //aqui transforma em numero
    }else if(c[i] == '+'){ //pega o primeiro e transforma em numero
      int num2 = pop(n1); // tira do inicio, e não precisa do get_peek pq ele já roda de 1 em 1
      int num1 = pop(n1);
      push(n1, num1 + num2); // empilha na prox lista o numero
    }else if(c[i] == '-'){
      int num2 = pop(n1);
      int num1 = pop(n1);
      push(n1, num1 - num2);
    }else if(c[i] == '*'){
      int num2 = pop(n1);
      int num1 = pop(n1);
      push(n1, num1 * num2);
    }else if(c[i] == '/'){
     int num2 = pop(n1);
      int num1 = pop(n1);
      push(n1, num1 / num2);
    }
    i++;

  }
  while (!empty(n1)) { //caso não esteja vazia
    printf("%d ", pop(n1));
  }
  printf("\n");
  destroy(n1);

  
}

int main () {
  char *c = "9 0 1 + 2 3 * * +" ;
  /*saida desejada: 
  9 0 1 + 2 3 * * +
  */
  //reversed_polish_notation (c);
  /*(9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )*/
  compute_polish_expression(c);
  return 0;
}
