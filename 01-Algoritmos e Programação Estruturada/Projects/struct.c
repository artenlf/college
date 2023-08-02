#include <stdio.h>

struct person
{
  char fName[20];
  int age;
  float height;
};

int main()
{
  struct person dataPerson1;

  printf("\n Digite o nome: ");
  scanf("%s", dataPerson1.fName);
  printf("\n Digite a idade: ");
  scanf("%d", &dataPerson1.age);
  printf("\n Digite a altura: ");
  scanf("%f", &dataPerson1.height);

  printf("\n Dados atribuidos");
  printf("\n %s", dataPerson1.fName);
  printf("\n %d", dataPerson1.age);
  printf("\n %f", dataPerson1.height);
}
