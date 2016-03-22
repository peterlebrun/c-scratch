#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <inttypes.h>

void die(const char *message) {
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

/*
 * Experiment with building fibonacci numbers as a linked list
 * To be continued another day
typedef struct fibonacci_number {
  int index;
  int value;
  struct *one_ago;
  struct *two_ago;
}

void print_fib(fibonacci_number *fib) {
  printf("%d: %d\n", fib->index, fib->value);

void print_n_fibonacci_numbers(int n) {
  for (int i = 0; i < n; i++) {
    if (i = 0) {
      fibonacci_number f0;
    }

  }
}
*/

/*
 * This gets really slow after about 40 numbers
 */
int get_nth_fibonacci(int n) {
  int i, nth_fib;

  for (i = n; i > 0; i--) {
    if (i == 0) {
      return 0;
    } else if (i <= 2) {
      return 1;
    } else {
      return get_nth_fibonacci(i - 1) + get_nth_fibonacci(i - 2);
    }
  }
}

int main(int argc, char *argv[]) {
  //if (argc != 2) die("Incorrect number of arguments. Use: fibonacci int");

  char* endptr;
  int fib_count = strtoimax(argv[1], &endptr, 10);

  if (fib_count < 1) die("Argument must be greater than 0");

  int i;
  for (i = 0; i < fib_count; i++) {
    printf("%d: %d\n", i, get_nth_fibonacci(i));
  }

  return 0;
}
