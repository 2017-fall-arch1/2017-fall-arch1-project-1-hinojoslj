#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "llist.h"		
#include <string.h>

// Allocate memory for a tree
tree *llAlloc()
{
  printf("Allocating Memory!\n");
  tree *binaryTree = (tree *)malloc(sizeof(tree));
  binaryTree -> treeRoot = NULL;
  //doCheck(lp);
  return binaryTree;
}

//Insert a new node into the Binary Search Tree, like root or parent..
//Modeled after the llPut method
void *insert(tree *leaf, char *name)
{
    //~~~~~~DEFINITIONS!~~~~~~~~~~
    //tree : { treeNode *treeRoot}
    //treeNode : {char *name treeNode *left, *right}
  printf("~~Inserting!~~\n");
  
  treeNode *tempNode; //Temporary Node
  int length; //Length of the name
  char *nameCopy; //Copy of the name
  
  //Allocate memory for tempNode
  tempNode = (treeNode *) malloc(sizeof(treeNode));

    for (length = 0; name[length]; length++) // compute length
    ;
    //Allocate memory for word with word.length into nameCopy
  nameCopy = (char *) malloc((length) + 1);
  //Now copy each character from the array of name into the array nameCopy
  for(length = 0; name[length]; length++)
    nameCopy[length] = name[length];
  nameCopy[length] = 0;

  tempNode -> name = nameCopy; //tempNode will now hold the nameCopy
  tempNode -> left = NULL; //Left will be empty
  tempNode -> right = NULL; //Right willbe empty

  leaf -> treeRoot = newTreeNode(leaf -> treeRoot, tempNode);

}

//Makes a new node for the BST, like leaves or children..
treeNode *newTreeNode(treeNode *root, treeNode *leaf)
{
    printf("Making a new node!!\n");
    int cond; //Condition of string comparisions 
    
    //If the tree is empty, return a new node
  if(root == NULL) 
      return leaf;
  //Else go down the tree
  
  cond = strcmp(leaf -> name, root -> name);
  if(0 > cond)
    root -> left = newTreeNode(root -> left, leaf);
  else
    root -> right = newTreeNode(root -> right, leaf);
  
  //Return the unchanged node pointer!
  return root;
}

//~~~~~~~~~~~~~~~~PRINT THE TREE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// print list membership.  Prints default mesage if message is NULL
void processPrint(tree *binaryTree)
{    
    FILE *fp; 
    fp = fopen("EmployeeNames.txt", "w");
    printLeaf(binaryTree -> treeRoot, fp);
}

void printLeaf(treeNode *leaf, FILE *fp)
{
        //Inorder printing
        if( leaf != NULL )
    {
        printLeaf(leaf -> left, fp);
        printf("%s\t", leaf -> name); //Print the file
        fprintf(fp, "%s\t", leaf -> name); //Write to file
        printLeaf(leaf -> right, fp);
    }
}

//~~~~~~~~~~~~~~~~~FILE METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
//TODO: If you are READING from the file then you are calling ~~~readFile at each line.
void readFile()
{
    FILE *fp; 
    char c; 
    fp = fopen("EmployeeNames.txt", "r");
    if(fp)
    {
        while(( c = getc(fp)) != EOF )
        {
            printf("%c", c);
            putchar(c);
        }
        fclose(fp);
    }
}
