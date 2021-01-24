#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    //TODO 
    tree=(Tree*)malloc(sizeof(Tree));
    tree->root=NULL;
    
}

void tree_insert(Tree *tree, int data)
{
	// TODO : Insert element to create a BST
	
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->right=temp->left=NULL;
	temp->data=data;
	struct node* q=(struct node*)malloc(sizeof(struct node));
	
	q=tree->root;
	
	if(q==NULL)
	{
		tree->root=temp;
		
	}
	else
	{
		while(q!=NULL)
		{
			if(data<q->data)
				q=q->left;
			else if(data>q->data)
				q=q->right;
		}
		q=temp;
		
	}
	 
}

void tree_delete(Tree *tree, int element)
{
   	// TODO : Delete elements from BST 
   	
   	//if no child
   	
   	
   	//if one child
   	
   	//if two children
   	  
}

void tree_inorder(Node *r)
{
 	//TODO :  use printf to print inorder 
 	if (r == NULL) 
        	return; 

     	tree_inorder(r->left); 
     	printf("%d ", r->data);
     	tree_inorder(r->right); 
     	 	
}

void tree_preorder(Node *r)
{
    	//TODO :  use printf to print preorder
    	if (r == NULL) 
        	return; 

     	printf("%d ", r->data); 
     	tree_preorder(r->left); 
     	tree_preorder(r->right); 
     	
}

void tree_postorder(Node *r)
{
    	//TODO :  use printf to print postorder
    	if (r == NULL) 
        	return; 
	
	printf("%s ", "2a");
     	tree_postorder(r->left); 
     	printf("%s ", "3a");
     	tree_postorder(r->right); 
     	printf("%d ", r->data); 
}

void postorder(Tree *t)
{
   	//TODO
   	//struct node* rt=(struct node*)malloc(sizeof(struct node));
   	//rt  = t->root;
   	if(t->root!=NULL)
   	{
   		
   		printf("%s\n", "1a");
   		//printf("%p\n", t->root);
   		//printf("%p\n", rt);
   		tree_postorder(t->root);
   	}
   	
}

void preorder(Tree *t)
{
     	//TODO
     	tree_preorder(t->root);
}

void inorder(Tree *t)
{
  	//TODO 
  	tree_inorder(t->root);  
}

void destroy(Node *r)
{
  	//TODO 
  	//inorder traversal and delete everything 
}

void tree_destroy(Tree *t)
{ 
	//TODO 
	//destroy(t->root);
	//free(t);   
}
