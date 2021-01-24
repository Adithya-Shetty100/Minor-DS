#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    //TODO 
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
// TODO : Insert element to create a BST
	Node *child=malloc(sizeof(Node));
	child->right=child->left=NULL;
	child->data=data;
	if(tree->root==NULL)
		tree->root=child;
	else{
		Node *p=NULL;
		Node *c=tree->root;
		while(c!=NULL){
			p=c;
			if(data>c->data)
				c=c->right;
			else
				c=c->left;
		}
		if(data>p->data)
			p->right=child;
		else
			p->left=child;
	}
}
void tree_delete(Tree *tree, int element)
{
        // TODO : Delete elements from BST   
        Node *p=NULL;
	Node *c=tree->root;
	Node *child=NULL;
	while(c!=NULL && c->data!=element){
		p=c;
		if(element>c->data)
			c=c->right;
		else
			c=c->left;
	}
	if(c==NULL){
		printf("Element not found\n");
		return;
	}
	if(c->right==NULL || c->left==NULL){
			if(c->right==NULL)
				child=c->left;
			else
				child=c->right;
				
			if(p==NULL)
				return;
			else if(c=p->left)
				p->left=child;
			else
				p->right=child;
			free(c);
	}
	else{
		Node *q=NULL;
		Node *d=c->right;
		while(d->left!=NULL){
			q=d;
			d=d->left;
		}
		c->data=d->data;
		if(q!=NULL)
			q->left=d->right;
		else
			c->right=d->right;
		free(d);
		}
		

	return;	
}

void tree_inorder(Node *r)
{
 	//TODO :  use printf to print inorder 
  	if(r!=NULL)
 	{
 		tree_inorder(r->left);
 		printf("%d\t",r->data );
 		tree_inorder(r->right);
 	}
}

void tree_preorder(Node *r)
{
    //TODO :  use printf to print preorder
    if(r!=NULL)
    {
    	printf("%d\t",r->data );
    	tree_preorder(r->left);
    	tree_preorder(r->right);
    }
}

void tree_postorder(Node *r)
{
    //TODO :  use printf to print postorder
    if(r!=NULL)
    {
    	tree_postorder(r->left);
    	tree_postorder(r->right);
    	printf("%d\t",r->data);
    }

}

void postorder(Tree *t)
{
   //TODO
   tree_postorder(t->root);
   printf("\n");
}

void preorder(Tree *t)
{
     //TODO
     tree_preorder(t->root);
     printf("\n");
}

void inorder(Tree *t)
{
  //TODO   
  tree_inorder(t->root);
  printf("\n");
}

void destroy(Node *r)
{
  //TODO 
  if(r!=NULL)
  {
  	destroy(r->left);
  	destroy(r->right);
  	free(r);
  } 
}

void tree_destroy(Tree *t)
{ 
//TODO    
	destroy(t->root);
}
