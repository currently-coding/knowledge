#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 7

int main() {
    const int src[SIZE] = {3, 5, 7, 12, 34, 77, 101}; 
    // array, in das geschrieben wird
    int dst[SIZE] = {0}; 

    for (int i = 0; i < SIZE; i++) {
        // pow ist eine Funktion aus math.h
        // ohne würde es so gehen:
        // dst[i] = src[i] * src[i];
        dst[i] = pow(src[i], 2);
        printf("%d, ", dst[i]);
    }

    printf("\n");
    printf("%d, %d", dst[0], dst[1]);
    printf("\n");

    return 0;
}