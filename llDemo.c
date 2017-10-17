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
  // LList *tree;      /*   OLD-- Makes a new tree!    */
  
  printf("Allocated Memory for tree succesfully!\n Attemping to insert now:\n");

  //tree = NULL;
  while (gets_n(buf, 100))	/* build list */
    // llPut(lp, buf);
     binaryTree = insert(binaryTree, buf);
      
     processPrint(binaryTree);
     printf("You have successfully inserted!\n");

    //llMakeEmpty(lp);

  printf("After emptying the list...\n");
  //llPrint(lp, 0);		/* default message */

  //llFree(lp);
  
  return 0;
}
