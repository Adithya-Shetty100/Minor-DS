#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

void tree_initialize(Tree *tree)
{
    	//TODO
    	Tree *temporary;
    	temporary=(Tree*)malloc(sizeof(Tree));
    	*tree=*temporary;
    	tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
    	//TODO
    	Node * temporary = (Node*)malloc(sizeof(Node));
    	Node * curr = tree->root;
    
    	temporary->data = data;
    	temporary->left = NULL;
    	temporary->leftThread = 1;
    	temporary->right = NULL;
    	temporary->rightThread = 1;

    	if (curr == NULL)
    	{
        	tree->root = temporary;
        	return;
    	}

    	while (1)
    	{
        	if (data < curr->data)
        	{
            		if (curr->leftThread == 0)
            		{
                		curr = curr->left;
            		}

            		else 
            		{
                		break;
            		}
        	}

        	else
        	{

            		if (curr->rightThread == 0)
            		{
                		curr = curr->right;
            		}
            		else
            		{
                		break;
            		}
        	}
    	}

    	if (data < curr->data)
    	{	
        	temporary->left = curr->left;
        	temporary->right = curr;  
        	curr->leftThread = 0;
        	curr->left = temporary;
    	}

    	else
    	{

        	temporary->right = curr->right;
        	temporary->left = curr;
        	curr->rightThread = 0;
        	curr->right = temporary;
    	}

}

Node *inorder_predecessor(Node *ptr)
{
   	//TODO
    	Node * temporary = ptr;

    	if(ptr==NULL) 
        	return NULL;
    	if(ptr->leftThread==1) 
        	temporary=temporary->left;

    	else
    	{
        	temporary=temporary->left;
        	while(temporary->right!=NULL && temporary->rightThread==0)
        	{
            		temporary=temporary->right;
        	}	
    	}
    	return temporary;
}


Node *inorder_successor(Node *ptr)
{
   	//TODO
    	Node *temporary=ptr;
    	if(ptr==NULL) 
    		return NULL;
    	if(ptr->rightThread==1) 
    		temporary=temporary->right;
    	else
    	{
        	temporary=temporary->right;
        	while(temporary->left!=NULL && temporary->leftThread==0)
        	{
            		temporary=temporary->left;
        	}
    	}
    	return temporary;
}

void print_ascending(Tree *tree)
{
    	if (tree->root == NULL)
    	{
        	printf("Empty\n");
        	return;
    	}

    	// TODO : Use printf() specified in tbtmain.c. Dont use printf statement
    	Node * temporary = tree->root;

    	while(temporary->leftThread==0)
    	{
        	temporary = temporary->left;
    	}
    	while(temporary!=NULL)
    	{
        	printfun(temporary->data);
        	temporary = inorder_successor(temporary);
    	}
    	nextline();
}

void print_descending(Tree *tree)
{
   	 if (tree->root == NULL)
    	{
        	printf("Empty\n");
        	return;
    	}	
	// TODO : Use printf() specified in tbtmain.c. Dont use printf statement 
	
    	Node * temporary = tree->root;
    	while(temporary->rightThread==0)
    	{
        	temporary=temporary->right;
    	}

    	while(temporary!=NULL)
    	{
        	printfun(temporary->data);
        temporary = inorder_predecessor(temporary);
    	}
    	nextline();
}

void destroy(Node *r)
{
    	//TODO
    	if(r==NULL) 
        	return;
    	if (r->left == NULL && r->right == NULL)
    	{
        	free(r);
        	return;
    	}
    	if (r->left != NULL && r->leftThread == 0)
    	{ 
        	destroy(r->left);
    	}
    	if (r->right != NULL && r->rightThread == 0)
    	{
        	destroy(r->right);
    	}
}

void tree_destroy(Tree *t)
{
    	destroy(t->root);
}
