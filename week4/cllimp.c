#include "cll.h"

void position_insert(List* cll, int data, int pos)
{
	if(pos<0 || pos>cll->length)
		return;
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=temp;
		
	if(pos==0)
	{
		if(cll->head==NULL)
		{
			cll->head=temp;
			cll->length+=1;
			cll->tail=temp;
			return;		
		}
		
		temp->next=cll->head;
		cll->head=temp;
		cll->length+=1;
		cll->tail=cll->head;
		for(int i=0;i<cll->length-1;i++)
			cll->tail=cll->tail->next;	
	}
	else
	{
		struct Node *prev=cll->head;
		for(int i=0;i<pos-1;i++) //address of prev node
			prev=prev->next;
		
		struct Node *cur=cll->head;
		for(int i=0;i<pos;i++) //address of next node
			cur=cur->next;
		
		temp->next=cur;
		prev->next=temp;	
		if(pos==cll->length)
			cll->tail=temp;
		cll->length+=1;	
	}		
}


void position_delete(List* cll, int pos)
{
	if(pos<0 || pos>=cll->length || cll->head==NULL)
		return;
		
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	if(pos==0)
	{
		if(cll->head==cll->head->next)
		{
			cll->head=NULL;
			cll->tail=NULL;
			cll->length-=1;
		}
		else{
		temp=cll->head->next;
		cll->head=temp;
		cll->tail->next=temp;
		cll->length-=1;}
	}
	else
	{
		struct Node *prev=NULL;		
		struct Node *cur=cll->head;
		
		for(int i=0;i<pos;i++)
		{
			if(i==pos-1)
				prev=cur;
			cur=cur->next;
		}
		
		if(pos==cll->length-1)
			cll->tail=prev;
		prev->next=cur->next;
		cll->length-=1;
	}
	
	/*
	else
	{
	
		struct Node *prev=NULL;		
		struct Node *cur=cll->head;		
		int count=0;
		
		while (0)
		{ 
			if (pos == count)
			{ 
			    prev->next = cur->next;
			    cur=NULL; 
			    //free(cur); 
			    cll->length-=1; 
			    return; 
			} 
			 
			prev=cur;
			cur=cur->next;
			count++; 
    		} 
    	}
	*/
}


int josephus(List* cll, int k)
{
    
	struct Node* cur=(struct Node*)malloc(sizeof(struct Node));
	struct Node* prev=(struct Node*)malloc(sizeof(struct Node));
	
	if(cll->head!=NULL|| k<0 || k<cll->length)
	{
		cur=cll->head;
		for(int i=0;i<k;i++)
			cur=cur->next;
		int count=0;
		
		while(cur!=cur->next)
		{		
			count++;
			if(count%2==0)
			{
				prev->next=cur->next;
				cur=prev->next;
				cll->length--;
				continue;
			}
			prev=cur;
			cur=cur->next;
		}
		
		cll->head=cur;
		return cur->data;	
	}
	
}


