#include<stdio.h>

int factorialTailRecursion(int n) {
  return factorialAux(n, 1);
}

int factorialAux(int n, int partial) {
    if(n != 1) { 
        return factorialAux(n - 1, partial * n); 
    } else {
        return partial;
    }
}
int main() {
    int n, result;
    printf("\nType a positive integer value: \n");
    scanf("%d", &n);
    result = factorialTailRecursion(n);
    printf("\nResult = %d", result);
    return 0;
}