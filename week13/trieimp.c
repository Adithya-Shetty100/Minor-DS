#include<stdio.h>
#include "trie.h"
struct trienode *getnode()
{
	//TODO
	int n;
	struct trienode *t;
	t=(struct trienode*)malloc(sizeof(struct trienode));
	for(n=0;n<26;n++)
	{
  		t->child[n]=NULL;
	}
	t->endofword=0;
	return t;
}

void insert(struct trienode *root, char *key)
{
	//INSERTING A VALUE
	//TODO
	int n,index;
	struct trienode *curr;
	curr=root;
	for(n=0;key[n]!='\0';n++)
	{
		index=key[n]-'a';
		if(curr->child[index]==NULL)
		{
  			curr->child[index] = getnode();
		}
		curr=curr->child[index];
	}
	curr->endofword=1;
}


void display(struct trienode *curr)
{
	//DISPLAYING A VALUE
	//TODO:
	int i,j;
	for(i=0;i<26;i++)
	{
  		if(curr->child[i]!=NULL)
  		{
    			word[length++]=i+'a';//
    			if(curr->child[i]->endofword==1)//if word found
    			{
    				word[length++]='\0';//
      				for(j=0;j<length;j++)
          				printf("%c",word[j]);
    			}
    			display(curr->child[i]);
  		}
	}
	length--;
	return;
	//Note : DO NOT USE printf() statement, use printfun() and   newline function for printing output 
}

int search(struct trienode * root,char *key)
{
	//TODO
	int n,index;
	struct trienode *t;
	t=root;
	for(n=0;key[n]!='\0';n++)
	{
  		index=key[n]-'a';
  		if(t->child[index]==NULL)
    			return 0;
  		t=t->child[index];
	}	
	if(t->endofword==1)
    		return 1;
	return 0;
}


void delete_trie(struct trienode *root,char *key)
{
  	//TODO
	int n,index,flag;
	struct stack popper;
	struct trienode* t;
	t=root;
	for(n=0;key[n]!='\0';n++)
	{	
  		index=key[n]-'a';
  		//no more letters in trie
  		if(t->child[index]==NULL)
    			return;

  		push(t,index);
  		t = t->child[index];
	}
	t->endofword=0;
	//PUSHING INTO THE STACK
	push(t,-1);
	while(1)
	{
  		popper=pop();
  		if(popper.index!=-1)
    		popper.m->child[popper.index]=NULL;
    		if(popper.m==root)
      			break;
    		flag=check(popper.m);
    		if((flag>=1)||(popper.m->endofword==1))
      			break;
    		else
      			free(popper.m);
	}
}


int check(struct trienode *x)
{
	//TODO
	int n,count=0;
	//RUN THE LOOP FOR ALL THE CHARACTERS IN THE ENGLISH ALPHABET
	for(n=0;n<26;n++)
	{
  		if(x->child[n] != NULL) 
    			++count;
  		else
    			continue;
}
return count;
}

void push(struct trienode *x,int k)
{
	//TODO
	//PRE-INCREMENTING TOP
	++top;
	s[top].m = x;
	s[top].index = k;
} 

struct stack pop()
{
	//TODO
	//STORING THE STACK TO DELETE
	struct stack delete_stack;
	delete_stack = s[top];
	top = top - 1 ;
	return delete_stack;
}



