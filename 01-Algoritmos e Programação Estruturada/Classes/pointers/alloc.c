#include <stdio.h>
#include <stdlib.h>

int* allocate() {
  int *memory = (int*) malloc(sizeof(int));

  return memory;
}

int main() {
  int *number = allocate();
  if (number != NULL) {
    printf("\n Type an integer number: ");
    scanf("%d", number);
    printf("\n The Number typed was: %d", *number);
  }

  return 0;
}