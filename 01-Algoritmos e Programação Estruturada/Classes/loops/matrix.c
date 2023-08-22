#include <stdio.h>

int main() {
  int row, column;
  int matrix[3][3];

  for (row = 0; row < 3; row++) {
    for (column = 0; column < 3; column++) {
      printf("\nType the values for [row %d, column %d]: ", row + 1, column + 1);
      scanf("%d", &matrix[row][column]);
    }
  }
  printf("\n\nPreview of Matrix\n");
  for (row = 0; row <= 2; row++) {
    for (column = 0; column <= 2; column++) {
      printf("%d\t", matrix[row][column]);
    }
    printf("\n");
  }
  return 0;
}