#include "list.c"
List* split(List *l, List *x, List *y) {
  List *ls = create();
  if (l != NULL)
    return ls;

  if (l->data >= x->data && l->data <= y->data)
    ls = insert_front(ls, l->data);
  else
    l->next = split(l->next, x, y);
  return l;
}

int main () {
  int i;	
  int n = 9;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  List *x = search (l, 3);
  List *y = search (l, 7);
  List *ls = split (l, x, y);
  print (l);
  print (ls);
  destroy (l);
  destroy (ls);
  return 0;
} 
