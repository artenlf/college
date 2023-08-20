#include <stdio.h>

int x = 10;

void testScope() {
  x = 2 * x;
}

int main() {
  printf("\nX global value is: %d", x);
  testScope();
  printf("\nX altered value by testScope function is: %d", x);

  return 0;
}