#include<stdio.h>

int* generateRandomNumber() {

    static int array[10];
    int a;

    for(a = 0; a < 10; a++) {
        array[a] = rand() % 100;
        printf("\narray[%d] = %d", a, array[a]);
    }
    return array;
}

int main(){

   int *p;
   int i;

   p = generateRandomNumber();

   for ( i = 0; i < 10; i++ ) {
      printf("\np[%d] = %d", i, p[i]);
   }
   return 0;
}
