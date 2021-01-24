#include "poly.h"

void insert_at_end(List *list, int data) 
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->link=NULL;
	
	if(list->head==NULL)
	{
		list->head=temp;
		list->number_of_nodes+=1;
		return;
	}
	
	struct Node* last=list->head;
	while(last->link!=NULL){
		last=last->link;
	}
	
	last->link=temp;
	list->number_of_nodes+=1;
	return;	
}

long long int evaluate(List *list, int x)
{

	int num=list->number_of_nodes;
	int ans=0,a=0,b=1;
	struct Node*p=list->head;
	if(p==NULL){
		return 0;
	}
	
	for(int i=0;i<num;i++)
	{
		a=p->data;
		p=p->link;
		if(i==0)
			b=1;
		else
			b*=x; //squaring the number
		ans+=a*b;
	}
	
	return ans;
}
