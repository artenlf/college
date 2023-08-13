#include <stdio.h> 
#include <ctype.h>

#define NAME_SIZE 30

int main() {
    char name[NAME_SIZE];
    int i;
    printf("\nType the name of the student: ");
    fgets(name, NAME_SIZE, stdin);
    printf("\nName BEFORE to uppercase method: %s", name);
    
    for(int i = 0; i < NAME_SIZE; i++) {
        name[i] = toupper(name[i]);
    }
    
    printf("\nName AFTER to uppercase method: %s", name);
    return 0;
}
