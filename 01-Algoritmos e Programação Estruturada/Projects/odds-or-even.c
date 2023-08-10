#include <stdio.h>

int main()
{
  int number;
  printf("\n Type a number from 1 to 100: ");
  scanf("%d", &number);

  if(number % 2 == 0) {
    printf("\n %d is an even number.", number);
  } else {
    printf("\n %d is an odd number.", number);
  }
  return 0;
}
