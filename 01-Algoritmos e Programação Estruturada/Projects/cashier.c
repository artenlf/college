#include <stdio.h>

main() {
  int operation;
  float amount;

  do {
      printf("\nSelect an operation: ");
      printf("\nType 1 to: Bank Statement.");
      printf("\nType 2 to: Deposit.");
      printf("\nType 3 to: Withdraw.");
      printf("\nType 4 to: Exit.");
      scanf("\n%d", &operation);

      switch (operation) {
        case 1:
          printf("\nProviding you a Bank Statement from the last 30 days.");
          break;
        case 2:
          printf("\nWhat is the amount to deposit?");
          scanf("%f", &amount);
          printf("\nThank you. Depositing %.2f...", amount);
        break;
        case 3:
          printf("\nWhat is the amount to withdraw?");
          scanf("%f", &amount);
          printf("\nThank you. Withdrawing %.2f...", amount);
        break;
        case 4:
        printf("\nExiting the program. Goodbye!");
        operation = 4;
        break;
        
        default:
          printf("\nInvalid input! Select an operation between 1 - 4.");
          break;
      }
    } while (operation != 4);

  

  return 0;
}

