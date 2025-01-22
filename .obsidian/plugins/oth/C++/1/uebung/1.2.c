#include <stdio.h>
#include <string.h>

int search(FILE *fptr, char letter) {
  int letter_count = 0;
  char current_letter;

  while (!feof(fptr)) {
    current_letter = fgetc(fptr);
    if (current_letter == letter) {
      letter_count++;
    }
    // printf("%c", current_letter); // print text to stdout
  }
  return letter_count;
}

int find_in_file(char filepath[], char letter) {
  FILE *fptr;
  fptr = fopen(filepath, "r");

  if (fptr == NULL) {
    printf("Error: Cannot open file.");
    return 1;
  }

  int letter_count = search(fptr, letter);

  fclose(fptr);

  return letter_count;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Incorrect amount of arguments. Usage: ./lettercount <filepath> <char>");
    return 1;
  }
  if (strlen(argv[2]) != 1) {
    printf("Please pass a single character - not a string.");
    return 1;
  }

  int result = find_in_file(argv[1], *argv[2]);
  printf("Found %d occurences of %c", result, *argv[2]);

  return 0;
}
