#include <stdio.h>

int main()
{
  int test1 = 7;
  int test2 = 4;

  int average = (test1 + test2) / 2;

  if (average < 7)
  {
    printf("Aluno reprovado com a média: %d", average);
  }
  else
  {
    printf("Aluno aprovado com a média: %d", average);
  }

  return 0;
}
