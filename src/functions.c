#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

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
  char *start = str; 
  while(space_char(*start)){ //use space_char function
    start++;
  }
  return start;
}

char *word_terminator(char *word)
{
  char *end = word;
  if(*word == '\0'){
    return end;
  }
  else{
    while(non_space_char(*end)){ //probably needs another condition with \0
      end++;
    }
  }

  return end;
}

int count_words(char *str)
{
  str = word_start(str);
  int count = 0;
  while(*(str = word_terminator(str)) != '\0'){
    count++;
    if(*(str = word_start(str)) == '\0'){
      break;
    }
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
 
  char *new_word = malloc(sizeof(char) * (len + 1));
  
  for(int i = 0; i < len; i++){
    *new_word = *inStr;
    inStr++;
    new_word++;
  }
  *new_word = '\0';
  new_word = new_word - len; //return it back to start of the word
  return new_word;
}

char **tokenize(char* str)
{
  int words = count_words(str);
  char **array = (char**) malloc(sizeof(char) * (words + 1));
  char *end;
  int word_length;

  for(int i = 0; i < words; i++){
    str = word_start(str);
    end = word_terminator(str);
    word_length = end - str;
    array[i] = copy_str(str, word_length);
    str = end;
  }
  array[words] = '\0';
  return array;
}

void print_tokens(char **tokens)
{
  for(; *tokens != 0; ++tokens){
    printf("%s\n", *tokens);
  }
}

void free_tokens(char **tokens){
  for(int i = 0; tokens[i] != 0; i++){
    free(tokens[i]);
  }
  free(tokens);
}
