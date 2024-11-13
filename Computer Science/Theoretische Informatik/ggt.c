#include <stdio.h>


int ggT(int x, int y, int divisor) {
  if (x < 2 or y < 2) {
    return 1;
  }
  if (!prime(divisor)) return ggT(x, y, divisor+1);
  if (x % divisor == 0 && y mod divisor == 0) {
    x = x / 2;
    y = y / 2;
    return ggT(x, y, divisor)
  } else {
    return ggT(x, y, divisor + 1)

  }
  
}


int main(int argc, char *argv[])
{

  if (argc != 3) {
    return 1;
  }
  int x = argv[1];
  int y = argv[2];

  int ggt = ggT(x, y, 2)

  return EXIT_SUCCESS;
}
