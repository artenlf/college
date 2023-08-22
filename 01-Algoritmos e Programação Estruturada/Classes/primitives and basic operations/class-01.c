#include <stdio.h>

#define PI 3.14

int main()
{
  int age = 18;
  float salary = 1250.75;
  double discount_percentage = 2.5;
  char gender = 'F';
  float height = 1.63;

  printf("\n Age: %d", age);
  printf("\n Salary: %f", salary);
  printf("\n Discount (%): %f", discount_percentage);
  printf("\n Gender: %c", gender);
  printf("\n Height: %.3f", height);
  return 0;

  float value1 = 0, value2 = 0;

  printf("\n Digite o primeiro valor:");
  scanf("%f", &value1);
  printf("\n Digite o segundo valor:");
  scanf("%f", &value2);
  printf("Variável 1 = %.2f", value1);
  printf("Variável 2 = %.2f", value2);
  return 0;

  int x = 5;
  int y = 10;

  printf("\n Stored value in X: %d", x);
  printf("\n Stored value in Y: %d", y);

  printf("\n Memory address of X: %x", &x);
  printf("\n Memory address of Y: %x", &y);

  const float G = 9.80;

  printf("\n PI = %f", PI);
  printf("\n G = %f", G);
}