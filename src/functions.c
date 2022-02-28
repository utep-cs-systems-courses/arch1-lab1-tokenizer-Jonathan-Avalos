#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

//This method checks if a character is a space char
int space_char(char c)
{
  if(c == '\t' || c == ' ') {
    return 1;
  }
  return 0;
}

//This method checks if a character is a not a space char
int non_space_char(char c)
{
  if(c != '\t' && c != ' '){
    return 1;
  }
  return 0;
}

//This method moves a pointer to the first non space character after a space character
char *word_start(char *str)
{
  char *start = str; 
  while(space_char(*start)){ //use space_char function
    start++;
  }
  return start;
}

//This method moves a pointer to the first space character after a non space character
char *word_terminator(char *word)
{
  char *end = word;
  if(*word == '\0'){
    return end;
  }
  else{
    end = word_start(end);
    while(non_space_char(*end) && *end != '\0'){ 
      end++;
    }
  }
  return end;
}

//This method counts the amount of words in the string provided
int count_words(char *str)
{
  str = word_start(str);
  int count = 0;
  if(*str == '\0'){
    return count;
  }
  count++;
  //While the pointer is not '\0' then continue moving the pointer
  //And if the terminator is not '\0' then add 1 to count
  while(*(str = word_terminator(str)) != '\0'){
    if(*(str = word_start(str)) == '\0'){
      break;
    }
    count++;
  }
  return count;
}

//This method copies the string into memory
char *copy_str(char *inStr, short len)
{

  //Allocates memory for the string
  char *new_word = malloc(sizeof(char) * (len + 1));

  //Copies whatever is at pointer inStr into pointer new_word
  for(int i = 0; i < len; i++){
    *new_word = *inStr;
    inStr++;
    new_word++;
  }
  //Last address has the terminator 
  *new_word = '\0';
  
  //Return it back to the start of the word
  new_word = new_word - len;
  return new_word;
}

//This method tokenizes the string and uses all the previous methods
char **tokenize(char* str)
{
  //Count the words to allocate memory
  int words = count_words(str);
  
  //Allocate memory, create a double array to hold pointers
  char **array = (char**) malloc(sizeof(char*) * (words + 1));
  char *end;
  int word_length;

  //Copy each word from the string into the double array
  for(int i = 0; i < words; i++){
    str = word_start(str);
    end = word_terminator(str);
    word_length = end - str;
    array[i] = copy_str(str, word_length);
    str = end;
  }
  //Set the last index of the array to the terminator
  array[words] = '\0';
  return array;
}

//This method prints the tokens 
void print_tokens(char **tokens)
{
  int i = 0;
  for(; *tokens != 0; tokens++){
    printf("[%i] ", i);
    printf("%s\n", *tokens);
    i++;
  }
}

//This method frees the tokens
void free_tokens(char **tokens){
  
  for(int i = 0; *(tokens+i); i++){
    free(*(tokens+i));
  }
  free(tokens);
}
