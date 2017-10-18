#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included

typedef struct treeNode_
{
  char *name; //Name to be stored
  struct treeNode_ *left; //Left child to treeNode
  struct treeNode_ *right;//Right child to treeNode
} treeNode; //treeNode will be a leaf to the tree

typedef struct
{
  treeNode *treeRoot; //treeRoot will be the base of the tree
}tree; //Tree will be the whole tree

//extern int llDoCheck;		/* set true for paranoid consistency checking */

/*Allocate memory for the tree first!*/
tree *llAlloc(); //Modified Linkedlist llAlloc to accept tree structure

//~~~~~~~~~~~~~~~~~TO FIX!~~~~~~~~~~~~~~~~~~~~~~~~~

/* Insert into the BST */
void *insert(tree *leaf, char *name);

/* Make a new node for BST */
treeNode *newTreeNode(treeNode *root, treeNode *leaf);

void processPrint(tree *binaryTree);
void printLeaf(treeNode *leaf, FILE *fp);

#endif	/* included */
