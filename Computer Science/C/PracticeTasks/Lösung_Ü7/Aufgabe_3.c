#include <stdio.h>

int main(){
    char a[] = "Hi";
    char *p = a;
    int i = 0; 

    printf("\nVor der Schleife: a: %p, p: %p, i: %d\n", a, p, i);

    while (*p++) {
        i++;
        printf("\nIn der Schleife: a: %p, p: %p, i: %d\n", a, p, i);
    }
    printf("\nNach der Schleife a: %p, p: %p, i: %d\n\n", a, p, i);

    // zum Vergleich
    int j = 0; 
    printf("\nWert der Schleifenvariablen j in der Schleife: "); 
    for (j = 0; j < 2; j++) {
        printf("%d ", j);
    }
    printf("\nNach der Schleife ist j höher als in der Schleife: %d\n\n", j); 
}