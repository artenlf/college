#include <stdio.h>

float n1, n2;

float calcAvg() {  
  return (n1 + n2) / 2;
}

int main() {
  printf("\nType 2 numbers to calculate the average between them: ");
  scanf("%f %f", &n1, &n2);
  printf("\nThe avarage between %.2f and %.2f is: %.2f", n1, n2, calcAvg());

  return 0;
}

