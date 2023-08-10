#include <stdio.h>

int main()
{
  int age;
  printf("\n Type your age: ");
  scanf("%d", &age);

  if(age >= 18) {
    printf("\n You over 18 years. You can drive a car.");
  } else {
    printf("\n You under 18 years. You cannot drive a car.");
  }
  return 0;
}
