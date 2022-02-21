#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

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

  List *list = init_history();
  add_history(list, " My name is Jonathan Avalos");
  add_history(list, "list is probably working");
  add_history(list, "I have to run this thing");
  char *first = get_history(list, 1);
  printf("%s\n", first);
  print_history(list);
  free_history(list);
  
  
}

