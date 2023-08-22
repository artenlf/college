#include <stdio.h>

int main(void) {
  int stop_program = 0;
  float test_grade;

  printf("\nType the final grade of the student: ");
  scanf("%f", &test_grade);

  while (stop_program != 1) {
    if (test_grade < 0 || test_grade > 10)
    {
      printf("\nInvalid Grade! Please type a grade from 1 to 10: ");
      scanf("%f", &test_grade);
    } else {
      printf("\nGrade registered. Finalizing the program...");
      stop_program = 1;
    }
  }

  return 0;
}
