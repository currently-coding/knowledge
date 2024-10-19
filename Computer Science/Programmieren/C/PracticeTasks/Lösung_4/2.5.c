#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 7

// Funktion, um den Inhalt ausgeben zu lassen
// print_ascii_number fragt ab, ob der Inhalt als Zeichen oder Zahl 
// ausgegeben werden soll
void print_array(char array[SIZE], bool print_ascii_number) {
    for (int i = 0; i < SIZE; i++) {
        printf(print_ascii_number ? "%d " : "%c", array[i]);
    }
    printf("\n");
}


int main() {
    char array[SIZE] = {73, 110, 102, 111, 32, 49, 0};
    printf("\n");
    print_array(array, true);
    print_array(array, false);
    printf("\n");
    return 0;
}