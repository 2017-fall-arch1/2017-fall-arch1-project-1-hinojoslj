#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "llist.h"		
#include <string.h>

int llDoCheck = 1;		/* set true for paranoid consistency checking */

#define doCheck(_lp) (llDoCheck && llCheck(_lp))

// Allocate memory for a tree
tree *llAlloc()
{
  printf("Allocating Memory!\n");
  tree *binaryTree = (tree *)malloc(sizeof(tree));
  binaryTree -> treeRoot = 0;
  //doCheck(lp);
  return binaryTree;
}

//TODO: ERROR: segmentation fault (core dumped) 
    //Need to be fixed. Can only go up to a second name and program crashes!!
    
//Insert a new node into the Binary Search Tree, like root or parent..
//Modeled after the llPut method
void *insert(tree *leaf, char *name)
{
  printf("~~Inserting!~~\n");
  //int cond; //The condition when comparing strings

  /* ~~~~~~~~~~~OLD ATTEMPT AT INSERT~~~~~~~~~~~~~
  //If the tree is empty, return a new node
  if(treeNode == NULL) return newTree(*name); //newTree needs to take in string parameters for a name
  //Else go down the tree
  if((cond = strcmp(*name, treeNode -> *name)) == 0 )
    treeNode -> count++; //We have encountered a repeated word! Increase the count
  else if(cond < 0)
    treeNode -> left = insert(treeNode -> left, *name);
  else
    treeNode -> right = insert(treeNode -> right, *name);
  //Return the unchanged node pointer!
  return treeNode;
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  */

  printf("HEREEEEEEEEEEEEEEEEEEEEEE!");
  treeNode *tempNode; //Temporary Node
  int length; //Length of the name
  char *nameCopy; //Copy of the name
  
    for (length = 0; name[length]; length++) // compute length
    ;
    //Allocate memory for word with word.length into nameCopy
  nameCopy = (char *) malloc((length) + 1);
  //Now copy each character from the array of name into the array nameCopy
  for(length = 0; name[length] != '\0'; length++)
    nameCopy[length] = name[length];
  nameCopy[length] = 0;

  //Allocate memory for tempNode
  tempNode = (treeNode *) malloc(sizeof(treeNode));
  //tempNode -> count = 0; //Initialized to 0 because it is the first word!
  tempNode -> name = nameCopy; //tempNode will now hold the nameCopy
  tempNode -> left = NULL; //Left will be empty
  tempNode -> right = NULL; //Right willbe empty

  leaf -> treeRoot = newTreeNode(leaf -> treeRoot, tempNode);

}

/*
 * ~~~~~~~~~~ATTEMPT TO ADD A NEW NODE TO BST~~~~~~~~~~~~~
 */
//Makes a new node for the BST, like leaves or children..
treeNode *newTreeNode(treeNode *root, treeNode *leaf)
{
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //Make a temporary node while allocating memory space by grabbing the size of our node
  printf("Making a new node!\n");
  LList *tree = (LList *)malloc(sizeof(LList));
  tree -> left = tree -> right = NULL;
  tree -> *str = NULL;
  return tree;
  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  */
    printf("Making a new node!!\n");
  int cond; //Condition of string comparisions 
    
    //If the tree is empty, return a new node
  if(root == NULL) return leaf;
  //Else go down the tree
  
  //This is might cause problems.. Check logic: Can A BST Tree have something that also keeps counts of repeated words?
  cond = strcmp(leaf -> name, root -> name);
  //if(cond == 0 )
    //root -> count++; //We have encountered a repeated word! Increase the count
  if(cond < 0)
    root -> left = newTreeNode(root -> left, leaf);
  else
    root -> right = newTreeNode(root -> right, leaf);
  
  //Return the unchanged node pointer!
  return root;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//~~~~~~~~~~~~~~~~PRINT THE TREE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// print list membership.  Prints default mesage if message is NULL
void processPrint(tree *binaryTree)
{
    /** ~~~~~~~~~~~OLD LLPRINT~~~~~~~~~
     * void llPrint(LList *lp, char *msg)
  LLItem *ip;
  int count = 1;
  doCheck(lp); //check llist consistency
  puts(msg ? msg :" List contents:"); //
  for (ip = lp->first; ip; ip = ip->next) {
    printf("  %d: <%s>\n", count, ip->str);
    count++;
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
    **/
    
    printLeaf(binaryTree -> treeRoot);
}

void printLeaf(treeNode *leaf)
{
        //Inorder printing
    
    //puts(msg ? msg : " List contents: ");
    if( leaf != NULL )
    {
        printLeaf(leaf -> left);
        printf("%s\t", leaf -> name);
        printLeaf(leaf -> right);
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
~~~~~~~~~~~~~~~~~~METHODS OF CLASS~~~~~~~~~~~~~~~~~~
// recycle a list, discarding all items it contains
void llFree(LList *lp)
{
  doCheck(lp);
  llMakeEmpty(lp);
  free(lp);
}

// Delete all elements off of the list
void llMakeEmpty(LList *lp)
{
  LLItem *current = lp->first, *next;
  doCheck(lp);
  while (current) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  lp->first = lp->last = 0;	// list is empty 
  doCheck(lp);
}
  
// append a copy of str to end of list
void llPut(LList *lp, char *s)
{
  int len;
  char *scopy;
  LLItem *i;

  doCheck(lp);
  // w = freshly allocated copy of putWord
  for (len = 0; s[len]; len++) // compute length
    ;
  scopy = (char *)malloc(len+1);
  for (len = 0; s[len]; len++) // copy chars
    scopy[len] = s[len];
  scopy[len] = 0;			// terminate copy


  // i = new item containing s
  i = (LLItem *)malloc(sizeof(LLItem));
  i->str = scopy;
  i->next = 0;

  // append to end of list
  if (lp->last) {			// list not empty
    lp->last->next = i;
  } else {			// list empty
    lp->first = i;
  }

  // new item is last on list
  lp->last = i;
  doCheck(lp);
}

// print list membership.  Prints default mesage if message is NULL
void llPrint(LList *lp, char *msg)
{
  LLItem *ip;
  int count = 1;
  doCheck(lp);
  puts(msg ? msg :" List contents:");
  for (ip = lp->first; ip; ip = ip->next) {
    printf("  %d: <%s>\n", count, ip->str);
    count++;
  }
}

// check llist consistency
int llCheck(LList *lp)
{
  LLItem *ip;
  ip = lp->first;
  if (!ip) 
    assert(lp->last == 0);
  else {
    for (; ip->next; ip = ip->next);
    assert(ip == lp->last);
  }
  return 0;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//END OF CLASS

*/
