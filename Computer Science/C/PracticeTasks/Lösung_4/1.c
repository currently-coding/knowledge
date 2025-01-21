#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Bitte geben Sie eine Nummer ein: \n");

    int number = 0;
    scanf("%d", &number);

    for (int i = number * (-1); i <= number; i+=2) {
        printf("%d ", i);
    }

    for (int i = number-2; i >= (-1)*number; i-=2) {
        printf("%d ", i);
    }

    printf("\n");
}