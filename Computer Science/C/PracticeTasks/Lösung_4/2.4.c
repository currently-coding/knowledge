#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Funktion, um die Matrixwerte auszugeben
void print_matrix(int matrix[SIZE][SIZE]) {
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

int main() {

   // zweidimensionales Array
   int matrix[SIZE][SIZE] = {};

   // füllt die Matrix mit den Werten der äußeren Schleife
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         matrix[i][j] = i;
      }
   }
   print_matrix(matrix);

   // füllt die Matrix mit den Werten der inneren Schleife
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         matrix[i][j] = j;
      }
   }
   print_matrix(matrix);

   // und die Kombination aus beidem (war nicht Teil der Aufgabe)
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         matrix[i][j] = i+j;
      }
   }
   print_matrix(matrix);

   return 0;
}