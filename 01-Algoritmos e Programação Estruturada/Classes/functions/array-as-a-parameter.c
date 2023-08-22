#include<stdio.h>

// this function will insert values into the array
void insert(int a[]) {
    int i = 0;
    for(i = 0; i < 3; i++){
        printf("\nType a value for position %d: ", i);
        scanf("%d", &a[i]);
    }
}

// this function will print the inserted values on screen
void multiplyByTwoAndPrintOnScreen(int b[]) {
    int i = 0;
    for(i = 0; i < 3; i++){
        printf("\nNumber[%d] = %d", i, 2 * b[i]);
    }
}

/* the main function will get the values from the array, 
    multiply by 2 and then print doubled values on screen
*/
int main(){
    int numbers[3];
    printf("\nInserting into array... \n ");
    insert(numbers);
    printf("\n\nDouble of informed values: ");
    printOnScreen(numbers);
    return 0;
}
