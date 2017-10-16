#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included

/* a linked-list item modified for Binary Tree Node */
typedef struct LLItem_s {
  struct LLItem_s *next;
  //  struct LLItem_s *left; //The left side of the tree
  //  struct LLItem_s *right; //The right side of the tree
  int count;
  char *str; //The name we are holding
} LLItem;

/* a list of LLItems with BST Structure */
typedef struct {
  LLItem *first, *last, *left, *right;
} LList;

typedef struct treeNode
{
  char name;
  struct treeNode *left;
  struct treeNode *right;
} treeNode;

extern int llDoCheck;		/* set true for paranoid consistency checking */

/* create a new list */
LList *llAlloc();

/* Make a new node for BST */
LList *newTree();

/* Insert into the BST */
LList *insert(LList *treeNode);

/* free memory associated with a list, discarding all items it contains */
void llFree(LList *lp);

/* append a copy of str to end of list */
void llPut(LList *lp, char *s);

/* Delete all elements off of the list */
void llMakeEmpty(LList *lp);

/* print list membership.  Prints default mesage if message is NULL */
void llPrint(LList *lp, char *msg);

/* check llist consistency, always returns zero */
int llCheck(LList *lp);

#endif	/* included */
