#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

int main() {

   const int array1[SIZE] = {0, 1, 2};  // initialisiert die restlichen Elemente mit 0
   int array2[SIZE] = { };
   int equal = 0;

   // Initialisiert array2 mit 0en
   memset(array2, 0, sizeof(array1));

   printf("\nInhalt der Arrays: \n");
   for (int i = 0; i < SIZE; i++) {
      printf("%d, ", array1[i]);
   }
   printf("\n");

   for (int i = 0; i < SIZE; i++) {
      printf("%d, ", array2[i]);
   }
   printf("\n\n");
   
   // Vergleicht die ersten Elemente 
   equal = memcmp(array1, array2, sizeof(int));
   printf("array1[0] %s array2[0]\n", equal == 0 ? "==" : "!=");

   // Vergleicht die kompletten Arrays 
   equal = memcmp(array1, array2, sizeof(array1));
   printf("array1[0] %s array2[0]\n", equal == 0 ? "==" : "!=");

   printf("\n");


   return 0;
}