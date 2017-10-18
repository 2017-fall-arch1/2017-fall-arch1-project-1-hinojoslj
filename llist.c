#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "llist.h"		
#include <string.h>

//int llDoCheck = 1;		/* set true for paranoid consistency checking */

//#define doCheck(_lp) (llDoCheck && llCheck(_lp))

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

/*
 * ~~~~~~~~~~ATTEMPT TO ADD A NEW NODE TO BST~~~~~~~~~~~~~
 */
//Makes a new node for the BST, like leaves or children..
treeNode *newTreeNode(treeNode *root, treeNode *leaf)
{
    printf("Making a new node!!\n");
    int cond; //Condition of string comparisions 
    
    //If the tree is empty, return a new node
  if(root == NULL) 
      return leaf;
  //Else go down the tree
  
  //This is might cause problems.. Check logic: Can A BST Tree have something that also keeps counts of repeated words?
  cond = strcmp(leaf -> name, root -> name);
  //if(cond == 0 )
    //root -> count++; //We have encountered a repeated word! Increase the count
  if(0 > cond)
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
    FILE *fp; 
    fp = fopen("test.txt", "w");
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
//TODO: If you are WRITING to the file then you are ~~~writingFile as you print the names.
void readFile()
{
    //FILE *fp; 
    //fp = fopen("/Arch/2017-fall-arch1-project-1-hinojoslj/test.txt", w+);
    
}

void writeFile()
{
    //File *fp; 
    //fp = fopen("/Arch/2017-fall-arch1-project-1-hinojoslj/test.txt", w+);
    //fputs(leaf -> name, fp);
    
}
