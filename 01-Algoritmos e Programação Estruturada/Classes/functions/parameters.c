#include <stdio.h>

int sum(int a, int b) {
  return a + b;
}

int main() {
  int result;
  result = sum(5, 10);
  printf("\nThe result is: %d", result);


  return 0;
}