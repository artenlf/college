#include <stdio.h>

int main()
{
  int number1 = 0;
  int number2 = 0;

  printf("\n Type the first number: ");
  scanf("%d", &number1);
  printf("\n Type the second number: ");
  scanf("%d", &number2);

  printf("\n Are number1 and number2 equals? %d", number1 == number2);
  printf("\n Is number1 greater than number2? %d", number1 > number2);
  printf("\n Is number1 lesser than number2? %d", number1 < number2);

  return 0;
}
