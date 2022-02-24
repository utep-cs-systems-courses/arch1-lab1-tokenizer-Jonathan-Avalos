#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define SIZE 1000

void goto_tokens(char *input, List *list)
{
  printf("> ");
  fgets(input,1000,stdin);
  add_history(list, input);
  char **tokens = tokenize(input);
  print_tokens(tokens);
  free_tokens(tokens);
}

void goto_history(char *input, List *list)
{
  print_history(list);
  putchar('>');
  fgets(input,100,stdin);
  char *str = get_history(list, atoi(input));
  printf("String at %i: %s\n",atoi(input), str);
}

void main()
{
  char input[1000];
  List *list = init_history();
  printf("Welcome to my Tokenizer. Enter 't' to Tokenize, 'h' to see the History, and 'q' to Exit.\n");
  while(1){
    putchar('$');
    fgets (input,1000,stdin);
    if (*input == 't'){
      goto_tokens(input, list);
    }
    else if (*input == 'h'){
      goto_history(input, list);
    }
    else if (*input == 'q'){
      exit(1);
    }
    else{
      printf("Invalid command. Please try again.\n");
    }
  }
}

  /* char test[] = " Jonathan Avalos";
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
  free_history(list);*/
  
  

