#include <stdio.h>

float calculateBMI() {
  float weight, height, bmi;

  printf("\n Enter your weight in kilograms: ");
  scanf("\n %d", &weight);
  printf("\n Enter your height in meters: ");
  scanf("\n %d", &height);

  bmi = weight / (height * height);

  return bmi;
}

int main() {
  float bmi = calculateBMI();

  if(bmi < 18.5) printf("\n BMI: %.2f. Be careful, you are currently under your normal weight.", bmi);
  if(bmi >= 18.5 && bmi < 24.9) printf("\n BMI: %.2f. Congratulations, your weight is just right.", bmi);
  else if (bmi >= 25) printf("\n BMI: %.2f. Be careful, you are currently over your normal weight.", bmi);

  return 0;
}