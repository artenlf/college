#include<stdio.h>

float squareNumber() {
    float number;
    printf("\nType a number: ");
    scanf("%f", &number);
    return number * number;
}

int main(){
    float squaredNumber = 0;
    squaredNumber = squareNumber();
    printf("\nThe square of the number typed is %.2f ", squaredNumber);
    return 0;
}