#include <stdio.h>
#define VEC_SIZE 11
#define VEC2_SIZE 6

float calculateMean(float array[], int size) {
  float sum = 0.0, result = 0.0;
  for(int i = 0; i < size; i++) {
    sum += array[i];
  }
  result = sum / (float) size;
  
  return result;
};
float calculateMedian(float array[], int size) {
  float result = 0.0;
  if (size % 2 != 0) {
    result = array[size / 2];
  } else {
    result = (array[size / 2] + array[(size / 2) -1]) / 2; 
  }
  return result;
}

int main() {
  float vector[VEC_SIZE] = { 1, 21, 23, 23, 45, 94, 96, 106, 209, 254, 314 };
  float vector2[VEC2_SIZE] = { 1, 21, 23, 23, 45, 94 };


  float meanVector = calculateMean(vector, VEC_SIZE);
  float medianVector = calculateMedian(vector, VEC_SIZE);
  printf("\nVector 1 Mean = %.2f", meanVector);
  printf("\nVector 1 Median = %.2f", medianVector);

  float meanVector2 = calculateMean(vector2, VEC2_SIZE);
  float medianVector2 = calculateMedian(vector2, VEC2_SIZE);
  printf("\nVector 2 Mean = %.2f", meanVector2);
  printf("\nVector 2 Median = %.2f", medianVector2);
}