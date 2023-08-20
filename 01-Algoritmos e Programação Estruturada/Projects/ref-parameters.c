#include<stdio.h>

void testParameters(int* n1, int* n2){
    *n1 = -1;
    *n2 = -2;
    printf("\n\nValues inside testParameters() function: ");
    printf("\nn1 = %d e n2 = %d", *n1, *n2);
}

int main(){
    int n1 = 10;
    int n2 = 20;
    printf("\nValues BEFORE calling testParameters() function: ");
    printf("\nn1 = %d e n2 = %d", n1, n2);

    testParameters(&n1, &n2);

    printf("\n\nValues AFTER calling testParameters() function: ");
    printf("\nn1 = %d e n2 = %d", n1, n2);

    return 0;
}
