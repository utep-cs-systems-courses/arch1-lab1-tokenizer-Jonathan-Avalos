#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

//Creates a new Linked List and allocates the memory for it.
//The root will be initialized to NULL.
List* init_history()
{
  List *history = malloc(sizeof(List*));
  history -> root = NULL;
  return history;
}

/*
  This method adds new strings into the List.
  If the root is NULL then we can set the new Item in that position.
  Else we find the next free space in the list using a while loop.
*/
void add_history(List *list, char *str)
{
  
  Item *item = malloc(sizeof(Item));
  
  //Will be use for the ID of the Item
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
  //Copy the string into the Item str
  char *copy = copy_str(str, length);
  item -> str = copy;
  //Set the next space to NULL
  item -> next = NULL;
}

/*
  This method recieves the List and an ID. Using a while loop, we move through
  the List until we move ID amount of times. If an Item is NULL and the ID is not 0
  then that ID does not exist, else return the string of that Item.
 */
char *get_history(List *list, int id)
{
  //Helps us iterate through the List.
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

/*
  This method prints the whole history List.
 */
void print_history(List *list)
{
  struct s_Item *temp = list -> root;
  while(temp != NULL){
    printf("[%i] %s\n", temp -> id, temp -> str);
    temp = temp -> next;
  }
}
/*
  This method frees all the Items and the List
 */
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
