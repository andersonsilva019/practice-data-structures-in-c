#include <stdio.h>
#include <stdlib.h>

void swap_address(int **a, int *b){
  *a = b;
  printf("x (Inside): %#p\n", *a);
}

int main(){

  int **x, *w, y = 5, z = 6;

  x = &w;
  
  *x = &y; // Faz com que x aponte para o endereço de y (w = &y)

  printf("%d\n", **x);

  printf("Address of y: %#p\n", &y);
  printf("Address of w: %#p\n", &w);
  printf("Address of z: %#p\n", &z);
  printf("x (Before): %#p\n", *x);
  swap_address(x, &z);
  printf("x (After): %#p\n", *x);

  printf("%d\n", **x);
  return 0;
}