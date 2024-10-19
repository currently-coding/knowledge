#include <stdio.h>
#include <stdlib.h>

#define SIZE 100


int main() {
    char buffer[SIZE];

    printf("Enter text\n");
    fgets(buffer, SIZE, stdin);

    printf("You entered: %s\n", buffer);
    
    return 0;
}