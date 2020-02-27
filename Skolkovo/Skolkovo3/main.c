#include <stdio.h>
#include "my_malloc.h"

const int SIZE = 4;

int main() {
  int* buf = (int*) mymalloc(sizeof (int) * SIZE);

  for(int i = 0; i<SIZE; i++){
    buf[i] = i + 1;
    printf("%d\t", buf[i]);
  }
  printf("\n");

  myfree(buf);

  for(int i = 0; i<SIZE; i++){
    printf("%d\t", buf[i]);
  }

  return 0;
}
