#include <stdio.h>

int sum (int value) {
  if (value == 0) {
    return value;
  } else {
    return value + sum(value - 1);
  }
}

  int main () {
    int number, result;
    printf("\nType a positive integer value: \n");
    scanf("%d", &number);
    result = sum(number);
    printf("\nResult = %d\n", result);

    return 0;
  }