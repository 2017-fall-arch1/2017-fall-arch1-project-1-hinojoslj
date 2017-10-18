#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "llist.h"		/* for list operations */


/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit)	
{
  char *p = s;			/* for indexing into s */
  char c;
  if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
      p++;
    if (c == '\n')		/* erase \n */
      *p = 0;
  }
  return (p - s);		/* #chars read (not including terminator or \n*/
}

int main()
{
  printf("Welcome to Laura's Arch Lab 1.\n");
  
  char buf[100];                /*The Buffer used to read and write to a file*/
  tree *binaryTree = llAlloc();	/* Allocates Memory for the tree! */
  
  printf("Allocated Memory for tree succesfully!\n Attemping to insert now:\n");

  while(strcmp(buf, "") != 0 )	/* build list */
  {
    printf("Input a name, or press enter to quit: \n");
    gets_n(buf, 100);
    if(strcmp(buf, "") == 0 ){
      break;
    }
    insert(binaryTree, buf);
  }
  
    processPrint(binaryTree);
    printf("You have successfully inserted!\n");
  
  return 0;
}
