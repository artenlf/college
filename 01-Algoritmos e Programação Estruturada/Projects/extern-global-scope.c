#include <stdio.h>

int x = 10;

int main() {
  int x = -5;
  int y;
  {
    extern int x;
    y = x;
  }

  printf("\n The value of x is: %d", x);
  printf("\n The value of y (equals to global x), which is: %d", y);

  return 0;
}