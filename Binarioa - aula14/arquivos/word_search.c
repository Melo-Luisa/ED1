#include <string.h>
#include <math.h>
#include "utils.c"

/* */
int linear_search (char **words, int n, char *key) {
  /*Terminar*/
  int i;
  for(i = 0; i< n; i++){
    if(strcmp(words[i],key) == 0){return i;}
  }
  return NOT_FOUND;
}

/* */
int binary_search_iterative (char **words, int n, char *key) {
  /*Terminar*/
  int esquerda = 0;
  int direita = n-1;

  while(esquerda <= direita){
    int meio = (direita + esquerda)/2;
    if(strcmp(words[meio],key) == 0){ //achou palavra
      return meio;
    }else if(strcmp(words[meio], key) < 0){ // palavra está mais a cima
      esquerda = meio + 1;
    }else if(strcmp(words[meio], key) > 0){
      direita = meio-1;
    }
    
  }
  return NOT_FOUND;

}

/* */
int binary_search_recursive (char **words, int l, int r, char *key) {
  /*Terminar*/

  if(l <= r){
    int meio = (l + r)/2;
    if(strcmp(words[meio],key) == 0){ //achou palavra
      return meio;
    }else if(strcmp(words[meio], key) < 0){ // palavra está mais a cima
      l =  binary_search_recursive ( words,  meio + 1,  r,  key);
    }else if(strcmp(words[meio], key) > 0){
      r = binary_search_recursive ( words,  l,  meio - 1,  key);
    }
    //return i;
  }
  return NOT_FOUND;


}

/* */
int get_number_of_lines (FILE *f) {
  int n = 0;
  if (f == NULL) 
    return n; 
  while (!feof(f)) {
    char c;
    fscanf(f, "%c", &c);
    if (c == '\n') 
      n++;
  }
  rewind(f);
  return (n-1);
}

/* */
int main () {
  /*if (argc < 2) { 
    printf("run: %s [word_to_search]\n", argv[0]);
    exit(1);
  }*/  
  clock_t start, end;
  double elapsed_time;
  //char *key = argv[1];
  char *key = "ACADEMICO";
  FILE *f = fopen("palavras.txt", "r"); 
  int n = get_number_of_lines(f);
  char **words = (char **)malloc(n * sizeof(char *));
  int i, index;
  for (i = 0; i < n; i++) 
    words[i] = (char *)malloc(256 * sizeof(char));
  i = 0;
  while (!feof(f)) {
    fscanf(f, "%s", words[i]);     
    i++;
  }

  /*Busca linear*/
  start = clock();
  index = linear_search (words, n, key);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time (linear): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  }
  else {
    printf("Element not found.\n");
  }
 
  // /*Busca binária iterativa*/
  // start = clock();
  // index = binary_search_iterative (words, n, key);
  // end = clock();
  // elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  // printf("Running time (binary): %.2f\n", elapsed_time);
  // if (index >= 0) {
  //   printf("Key %s, found at %d\n", key, index);
  // }
  // else {
  //   printf("Element not found.\n");
  // }
  
  // /*Busca binária recursiva*/
  // start = clock();
  // index = binary_search_recursive (words, 0, n-1, key);
  // end = clock();
  // elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  // printf("Running time (binary): %.2f\n", elapsed_time);
  // if (index >= 0) {
  //   printf("Key %s, found at %d\n", key, index);
  // }
  // else {
  //   printf("Element not found.\n");
  // }
 
  /*Desalocando estruturas*/ 
  for (i = 0; i < n; i++) 
    free(words[i]);
  free(words);
  fclose(f);
  return 0;
}  
