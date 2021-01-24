#include "et.h"

Node * createExpressionTree(char* a,int len)
{
    //TODO
	Node *parent,*current,*root = NULL;
	int j;
	Node *newNode;
	for(j=len-1;j>=0;j--)
	{
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = a[j];
		newNode->left = newNode->right = newNode->prev = NULL;
		if(root == NULL)
		{
			root = newNode;
			current = parent = root;
		}
		else
		{
			if(a[j]=='+'||a[j]=='-'||a[j]=='*'||a[j]=='/')
			{
				if(parent->right == NULL)
				{
					current = newNode;
					parent->right = current;
					current->prev = parent;
					parent = current;
				}
				else if(parent->left == NULL)
				{
					current=newNode;
					parent->left = current;
					current->prev = parent;
					parent = current;
				}
				else
				{
					while(parent->left!=NULL)
					{
						parent = parent->prev;
					}
					current = newNode;
					parent->left = current;
					current->prev = parent;
					parent = current;
				}
			}
			else
			{
				if(parent->right == NULL)
				{
					current = newNode;
					parent->right = current;
					current->prev = parent;
				}
				else if(parent->left == NULL)
				{
					current = newNode;
					parent->left = current;
					current->prev = parent;
				}
				else
				{
					while(parent->left!=NULL)
					{
						parent = parent->prev;
					}
					current = newNode;
					parent->left = current;
					current->prev = parent;
				}
			}
		}
	}
	return root;
}


void inorder(Node *root)
{
 	//TODO 
 	// Note : Do not change the printf
  	if(root!=NULL)
  	{
  		inorder(root->left);
  		printf("%c",root->data); 
  		inorder(root->right);
  	}
}

void preorder(Node *root)
{
 	//TODO 
 	// Note : Do not change the printf
	if(root!=NULL)
	{
  		printf("%c",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root)
{
 	//TODO 
 	// Note : Do not change the printf
 	if(root!=NULL)
 	{
  		postorder(root->left);
  		postorder(root->right);
 		printf("%c",root->data);
	}
}

void freeTree(Node *root)
{
	if(root == NULL) 
	  	return;
  	if(root->left == NULL && root->right == NULL)
  	{
    		free(root);
    		return ;
  	}
  	if(root->left!=NULL)
  	{
    		freeTree(root->left);
  	}
  	if(root->right!=NULL)
  	{
    		freeTree(root->right);
  	}
}
