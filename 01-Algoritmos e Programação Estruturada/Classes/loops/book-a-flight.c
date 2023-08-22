#include <stdio.h>
int main() {
    // Initial Matrix
    // rows represents a flight
    // columns represents a seat. 0 for available, 1 for occupied, -1 for unavailable
    int matrix[3][5] = {
        1, 1, 1, 0, -1,
        1, 1, 1, 1, 1,
        0, 0, -1, -1, -1
    };
    
    int option;
    int flightNumber;
    int booked;
    
    do  {
        printf("\n1 - Book a flight\n2 - Exit\nPlease select an option: ");
        scanf("%d", &option);
        switch(option) {
            case 1: 
                printf("Please choose a flight number from 1 - 3: ");
                scanf("%d", &flightNumber);
                booked = 0;
                if (flightNumber >= 1 && flightNumber <= 3) {
                    for(int i = 0; i < 5 && booked == 0; i++) {
                        if (matrix[flightNumber - 1][i] == 0) {
                            booked = 1;
                            matrix[flightNumber - 1][i] = 1;
                        }  
                    }
                    if (booked == 1) printf("\nCongratulations! Your flight has been booked!");
                    else printf("\nThere isn't any seats available in this flight!");
                } else {
                    printf("Error! Invalid input.");
                }
                break;
            case 2: 
                printf("\nExiting...");
                break;
            default: printf("Error! Invalid input.");
        }
    } while (option != 2);
    return 0;
}
