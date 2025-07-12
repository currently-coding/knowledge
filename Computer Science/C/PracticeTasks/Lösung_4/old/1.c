#include <stdio.h>
#include <stdlib.h>


int event_loop() {
    char buffer = 'x';
    while (1) {
        printf("Select between 1,2,3 or x to exit.\n");
        fflush(stdin);
        scanf(" %c", &buffer);
    
        if (buffer == 'x') {
            break;
        }
        
        const int num = atoi(&buffer);
        if (num < 1 || num > 3) {
            printf("Error, selection must be between 1 and 3.\n");
            continue;    
        }

        printf("Selection was %d\n", num);
    } 
    return 0;
}

int main() {
    return event_loop();
}