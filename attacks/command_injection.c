/*
 * This code demonstrates code that is vulnerable to a command injection
 * Calling this code like so:
 * ./command_injection "story.txt; ls; rm file; ls"
 * Will show that we are able to execute shell commands from within this system call.
 *
 * The starter code for this was inspired by the OWASP article on command injection.
 *
 * Use at your own risk.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char cat[] = "cat ";
  char *command;
  size_t commandLength;

  // We use argv[1] as our command to execute.  Ideally we want to sanitize or escape it first.

  // Sanitize example
  /*
  int i;
  for (i = 0; i < (int) strlen(argv[1]); i++) {
    if (';' == argv[1][i]) {
      argv[1][i] = ' ';
      printf("Nice try jerkwad!  Semi colon detected.\n");
    }
  }
  */

  commandLength = strlen(cat) + strlen(argv[1]) + 1 + 2; // last 2 are for quotes
  command = (char *) malloc(commandLength);
  strncpy(command, cat, commandLength);
  strncat(command, "'", 1);
  strncat(command, argv[1], (commandLength - strlen(cat)));
  strncat(command, "'", 1);

  system(command);

  return 0;
}
