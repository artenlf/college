#include <stdio.h>

int main()
{
  int counter = 0;
  do
  {
    counter++;
    printf("\nBook number %d successilly given.", counter);
  } while (counter < 5);
  
  return 0;
}

