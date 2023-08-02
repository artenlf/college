#include <stdio.h>

int main()
{

  int number1 = 2;
  int number2 = 4;

  int result = 43 % 3;

  printf("\n Sum: %d", number1 + number2 / number1);
  printf("\n Module: %d", result);

  int unary = number2++;

  printf("\n Unary Increment: %d", number2);
  return 0;
}