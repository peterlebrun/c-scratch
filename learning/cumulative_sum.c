#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Proper use: ./cumulative_sum XXX where XXX is some integer.\n");
    return 1;
  }

  int x = atoi(argv[1]);
  int cumulative_sum = ((x + 1) * x) / 2;

  printf("The cumulative sum from 1 to %d is %d\n", x, cumulative_sum);

  return 0;
}
