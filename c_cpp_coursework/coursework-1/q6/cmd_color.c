#include <stdio.h>
#include "cmd_color.h"

void red () {
  // every character printed after this sequence will be displayed red
  printf("\033[1;31m");
}

void blue () {
  // every character printed after this sequence will be displayed blue
  printf("\033[0;34m");
}

void reset () {
  // reset the color of the prompt (to white by default)
  printf("\033[0m");
}