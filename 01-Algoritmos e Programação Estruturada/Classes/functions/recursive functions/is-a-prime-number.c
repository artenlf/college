#include <stdio.h>

int isAPrimeNumber(int number) {
  return isAPrimeNumberAux(number, 2);
}

int isAPrimeNumberAux(int number, int x) {
  if (x == number) {
    return 1;
  } else if (number % x == 0) {
    return 0;
  } else {
    return isAPrimeNumberAux(number, x + 1);
  }
}

  int main() {
    int result = 0, number;
    printf("\nType a positive integer number: \n");
    scanf("%d", &number);

    result = isAPrimeNumber(number);

    if (result == 1) {
      printf("\nNumber %d is a Prime number!", number);
    } else {
      printf("\nNumber %d is not a prime number!", number);
    }

    return 0;
}