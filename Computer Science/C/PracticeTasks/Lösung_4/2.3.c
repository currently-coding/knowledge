#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

int main() {
   int array[SIZE] = {0};

   printf("\nWerte im Array vor der Initialisierung:\n");

   for (int i = 0; i <= SIZE; i++) {
      printf("array[%d] == %d\n", i, array[i]);
   }
   printf("\n");

   // Initialisierung des Arrays
   for (int i = 0; i <= SIZE; i++) {
      array[i] = i;
   }
   printf("\n");

   printf("Werte nach der Initialisierung: \n");
   for (int i = 0; i <= SIZE; i++) {
      printf("array[%d] == %d\n", i, array[i]);
   }
   printf("\n");
}