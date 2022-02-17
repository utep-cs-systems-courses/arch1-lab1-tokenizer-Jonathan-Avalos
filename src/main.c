#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define IN 1
#define OUT 0

int main()
{
  char test[] = " Jonathan Avalos ";
  char *ptr = test;
  printf("%s\n", word_start(ptr));
  printf("%s\n", word_terminator(ptr));
  printf("%i\n", count_words(ptr));
  printf("%s\n", copy_str(ptr, 17));
}

