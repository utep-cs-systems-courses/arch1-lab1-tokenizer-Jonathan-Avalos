#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history()
{
  List *history = malloc(sizeof(List*));
  history -> root = NULL;
  return history;
}

void add_history(List *list, char *str)
{
  
  Item *item = malloc(sizeof(Item));
  int count = 0;
  
  if(list -> root == NULL){
    list -> root = item;
  }
  else{
    struct s_Item *temp = list -> root;
    count++;
    while(temp -> next != NULL){
      count++;
      temp = temp -> next;
    }
    temp -> next = item;
  }
  
  item -> id = count;
  int length = 0;
  while(*str != '\0'){
    length++;
    str++;
  }
  
  str = str - length;
  char *copy = copy_str(str, length);
  item -> str = copy;
  item -> next = NULL;
}

char *get_history(List *list, int id)
{
  struct s_Item *temp = list -> root;
  while(temp != NULL && id != 0){
    temp = temp -> next;
    id--;
  }
  if(temp == NULL){
    printf("ID not in history\n");
  }
  else{
    return temp -> str;
  }
}

void print_history(List *list)
{
  struct s_Item *temp = list -> root;
  while(temp != NULL){
    printf("[%i] %s\n", temp -> id, temp -> str);
    temp = temp -> next;
  }
}

void free_history(List * list)
{
  struct s_Item *temp = list -> root;
  struct s_Item *temp_2;
  while(temp != NULL){
    temp_2 = temp -> next;
    free(temp -> str);
    free(temp);
    temp = temp_2;
  }
  free(list);
  list -> root = NULL;
}
