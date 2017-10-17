#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included

/* ~~~~~~~~~~~~~~~OLD!~~~~~~~~~~~~~~~~~~~~
// a linked-list item modified for Binary Tree Node
typedef struct LLItem_s {
  // struct LLItem_s *next;
  //  struct LLItem_s *left; //The left side of the tree
   struct LLItem_s *right; //The right side of the tree
  int count;
  char *str; //The name we are holding
} LLItem;

// a list of LLItems with BST Structure 
typedef struct {
  LLItem *first, *last, *left, *right;
} LList;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
typedef struct treeNode
{
  //int *count; //The amount of times a name was encountered
  char *name; //Name to be stored
  struct treeNode *left; //Left child to treeNode
  struct treeNode *right;//Right child to treeNode
} treeNode; //treeNode will be a leaf to the tree

typedef struct
{
  treeNode *treeRoot; //treeRoot will be the base of the tree
}tree; //Tree will be the whole tree

//extern int llDoCheck;		/* set true for paranoid consistency checking */

/*Allocate memory for the tree first!
//tree *llAlloc(); //Modified Linkedlist llAlloc to accept tree structure

//~~~~~~~~~~~~~~~~~TO FIX!~~~~~~~~~~~~~~~~~~~~~~~~~

/* Insert into the BST */
//LList *insert(LList *treeNode);
void *insert(tree *leaf, char *name);

/* Make a new node for BST */
//LList *newTree(); testing needed to check if logical
treeNode *newTreeNode(treeNode *root, treeNode *leaf);


//~~~~~~~~~~~Methods obtained from GitHUB!~~~~~~~~~~~~~~~~~


/* free memory associated with a list, discarding all items it contains */
//void llFree(LList *lp);

/* append a copy of str to end of list */
//void llPut(LList *lp, char *s);

/* Delete all elements off of the list */
//void llMakeEmpty(LList *lp);

/* print list membership.  Prints default mesage if message is NULL */
void processPrint(tree *binaryTree);
void printLeaf(treeNode *leaf);

/* check llist consistency, always returns zero */
//int llCheck(LList *lp);

#endif	/* included */
