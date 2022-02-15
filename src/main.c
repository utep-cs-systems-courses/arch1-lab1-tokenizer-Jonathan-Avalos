#include <stdio.h>
#include "tokenizer.h"

#define IN 1
#define OUT 0

int main()
{

  printf( "Please enter anything you want \n" );
  
  while(1){
    printf( "$ " );
    int c, white, nw, state;

    state = OUT;
    white = nw = 0;
    while ( ( c = getchar() ) != EOF && c != '\n')
    {
      char *str = c;
      
      /*if (space_char(c)){
	state = OUT;
	white++;
      }
      else  if(state == OUT && non_space_char(c)){
	state = IN;
	nw++;
	}*/
  
    }
  }
  return 0;
}

