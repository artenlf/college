#include<stdio.h>

int factorial(int value) {
    if(value != 1) { 
        return value * factorial(value - 1); 
    } else {
        return value;
    }
}
int main() {
    int n, result;
    printf("\nType a positive integer value: \n");
    scanf("%d", &n);
    result = factorial(n);
    printf("\nResult = %d", result);
    return 0;
}