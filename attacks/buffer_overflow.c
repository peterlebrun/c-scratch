/*
 * The code below demonstrates a buffer overflow.
 *
 * This was written solely for the academic purpose of understanding
 * attacks in an effort to be a better defensive programmer.
 *
 * This will probably compile fine with gnu gcc, but if you're having
 * problems where it either won't compile, or you're getting abort traps,
 * you'll need to compile like so:
 *
 * gcc buffer_overflow.c -fno-stack-protector -D_FORTIFY_SOURCE=0 -o buffer_overflow.c
 *
 * -fno-stack-protector tells gcc to compile even though you're using a dangerous
 * command (strcpy as opposed to strncopy)
 *
 * -D_FORTIFY_SOURCE=0 tells gcc not to throw the abort trap
 *
 * see http://stackoverflow.com/questions/3026361/performing-simple-buffer-overflow-on-mac-os-10-6 for more details
 *
 * Use at your own risk.
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  int foo = 0;
  char buf[1];

  printf("%p\n", &buf);
  printf("%p\n", &foo);

  // This will write the value 1 into the variable "foo" because
  // we aren't validating anything, checking boundaries, etc
  strcpy(buf, "a1");

  if (foo) { // we never assigned any value to foo except 0
    // Imagine if this was a super sensitive critical path
    // like maybe foo == 1 would allow advanced system permissions
    // or delete all your cat pictures
    printf("BUFFER OVERFLOWED");
  }

  printf("\n"); // keep that command line neat and clean

  return 0;
}
