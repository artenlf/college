#include <stdio.h>

int main()
{

int dayAsANumber;
printf("\nType a number from 1 to 7");
scanf("\n%d", &dayAsANumber);

  switch (dayAsANumber)
  {
  case 1:
  printf("\nSunday");
    break;
  case 2:
  printf("\nMonday");
    break;   
  case 3:
  printf("\nTuesday");
    break;
  case 4:
  printf("\nWednesday");
    break;
  case 5:
  printf("\nThurday");
    break;   
  case 6:
  printf("\nFriday");
    break;
  case 7:
  printf("\nSaturday");
    break;    

  default:
  printf("\nInvalid input! Must be between 1 and 7.");
    break;
  }
  return 0;
}
