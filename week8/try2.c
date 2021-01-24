#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
  	Tree *new_tree = (Tree *)malloc(sizeof(Tree));
  	new_tree->root = NULL;
  	// printf("\nTree initialized\n");

}

void tree_insert(Tree *tree, int data)
{
  	Node *parent = NULL,*temp = tree->root;
  	if(tree == NULL)
  	{	//  printf("Empty tree in insert fn\n");
    		return;
  	}

  	Node *new_node = (Node *)malloc(sizeof(Node));
  	new_node->data = data;
  	new_node->left = NULL;
  	new_node->right = NULL;
  	if(temp == NULL)
    		tree->root = new_node;
  	else
  	{
    		while(temp!=NULL)
    		{
      			parent = temp;
      			if(data < temp->data)
        			temp=temp->left;

      			else if(data > temp->data)
        			temp=temp->right;
    		}
      		if(data < parent->data)
        		parent->left = new_node;
      		else if(data > parent->data)
        		parent->right = new_node;

  }
  // printf("Inserted %d\n",data);

  
}

void tree_delete(Tree *tree, int element)
{
   	// TODO : Delete elements from BST  
   	
   	Node *temp = tree->root, *parent_node = NULL, *grandchild_node = NULL, *inorder_succesor = NULL;
   	
    	// Search 
    	while (temp != NULL && temp->data != element) 
    	{
        	if (element > temp->data) 
        	{
            		parent_node = temp;
            		temp = temp->right;
        	}

       		else if (element < temp->data) 
       		{
            		parent_node = temp;
            		temp = temp->left;
        	}
    	}	

    	if (temp == NULL) 
    	{
        	return;
    	}

    	else if (temp->left == NULL) 
    	{
        	grandchild_node = temp->right;
    	}


    	else if (temp->right == NULL) 
    	{
        	grandchild_node = temp->left;
    	}
        
    	else 
    	{
        	//inorder successor
        	inorder_succesor = temp->right;

        	while (inorder_succesor->left != NULL) 
        	{
            		inorder_succesor = inorder_succesor->left;
        	}


        	inorder_succesor->left = temp->left;
        	grandchild_node = temp->right;
    	}


    	if (parent_node == NULL) 
    	{
        	tree->root = grandchild_node;
    	}
    	else if (temp == parent_node->right) 
    	{
        	parent_node->right = grandchild_node;
    	}
    	else if (temp == parent_node->left) 
    	{
        	parent_node->left = grandchild_node;
    	}

    	free(temp);
    	temp=NULL; 

}

void tree_inorder(Node *r)
{
  	if (r != NULL) 
    	{   
        	tree_inorder(r->left);
        	printf("%d ", r->data);
        	tree_inorder(r->right);
    	}
}

void tree_preorder(Node *r)
{
    	if (r != NULL) 
    	{
        	printf("%d ", r->data);
        	tree_preorder(r->left);
        	tree_preorder(r->right);
    	}
    
}

void tree_postorder(Node *r)
{
  	if (r != NULL) 
    	{
        	tree_postorder(r->left);
        	tree_postorder(r->right);
        	printf("%d ", r->data);
    	}
}


void postorder(Tree *t)
{
  	if(t->root!=NULL)
  	{
    		tree_postorder(t->root);
    		printf("\n");
  	}
}


void preorder(Tree *t)
{
  	if(t->root!=NULL)
  	{
    		tree_preorder(t->root);
    		printf("\n");
  	}
}

void inorder(Tree *t)
{
  	if(t->root!=NULL)
  	{
    		tree_inorder(t->root);
    		printf("\n");
  	}  
}

void destroy(Node *r)
{
  	if(r==NULL)
    		return;

  	if(r->left==NULL && r->right==NULL)
    	{
      		free(r);
      		r=NULL;
      		return;
    	}
 	 if(r->left !=NULL)
  	{
    		destroy(r->left);
  	}
  	if(r->right !=NULL)
  	{
    		destroy(r->right);
  	}  
}

void tree_destroy(Tree *t)
{ 
  	
  	if (t == NULL) 
    		return;
  	else
  	{
    		
    		destroy(t->root);
    		free(t);
    		t=NULL;
  	}
}

