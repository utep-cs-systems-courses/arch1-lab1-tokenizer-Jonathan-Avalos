#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == '\t' || c == ' ') {
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if(c != '\t' && c != ' '){
    return 1;
  }
  return 0;
}

char *word_start(char *str)
{
  char *start;
  int i = 0;
  
  while(space_char(*(str + 1)){ //use space_char function
    i++;
  }

  start = str + i;
  return start;
}

char *word_terminator(char *word)
{
  char *end;
  int i = 0;

  while (non_space_char(*(word+i))){ //use not_space_char function
    i++;
  }
  
  end = word + i;
  return end;
}

char count_words(char *str)
{
  int count = 0;
  char *curr;
  
  while(*str != '\0'){
    curr = *word_start(*str);
    end = *word_terminator(*curr);
    str = end+1;
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  //here allocate memory for new word
  char *new_word;
  
  while((*inStr = *new_word) != '\0'){
    inStr++;
    new_word++;
  }
  return new_word;
}

char **tokenize(char* str)
{

}

void print_tokens(char **tokens)
{

}

void free_tokens(char **tokens){

}
