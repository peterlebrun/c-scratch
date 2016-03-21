#include <stdio.h>
#include <inttypes.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Proper use: ./cumulative_sum XXX where XXX is some integer.\n");
    return 1;
  }

  // Notice what we have to do here to get the integer value
  // from the command line arguments
  // This was tricky to wrap my head around
  char* endptr;
  int x = (int) strtoimax(argv[1], &endptr, 10);
  int cumulative_sum = ((x + 1) * x) / 2;

  printf("The cumulative sum from 1 to %d is %d\n", x, cumulative_sum);

  return 0;
}
