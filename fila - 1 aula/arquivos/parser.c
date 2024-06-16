#include "stack.c"


//caso de má formação
int parser (char *c) { // testa o char
  Stack *s = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') { // diferente de vazio significa que ainda tem elementos
    if(c[i] == '(' || c[i] == '[') {
      push(s, c[i]); //formar a ordem
    } 
    else if( c[i] == ']'){
      if(empty(s) || pop(s) == '('){
        return 0; // mal-formada
      }
    }
    else if(c[i] == ')'){
      if(empty(s) || pop(s) == '['){
        return 0; // mal-formada
      }
    }
    print(s);
    i++;

    //Caso fazia temos os conjuntos ok
    if(empty(s)) return 1;
    else return 0;    
  }
}

int main () {
  //char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  char *c = "( ) [ ]";
  //char *c = "( [ ]";
  //char *c = ") (";
  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  return 0;
}
