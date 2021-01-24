#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->link= NULL;
	
	if(list->head==NULL)
	{
		list->head=temp;
		list->number_of_nodes+=1; 
		//free(temp);
		return;	
	}
	
	struct Node* last=list->head;
	while(last->link!=NULL)
	{
		last=last->link;
	}
	
	last->link=temp;
	list->number_of_nodes+=1; 
	//free(temp);
	
}

void list_delete_front(List* list) {
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	
	if(list->head!=NULL)
	{
		temp=list->head;
		list->head=temp->link;
		list->number_of_nodes-=1; 
		free(temp);
		return;	
	}
	
}

void list_insert_at (List *list, int data, int position)
{
	if(position>(list->number_of_nodes))
		return;
	
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->link= NULL;
	
	if(position==0)
	{
		if(list->head==NULL)
		{
			list->head=temp;
			list->number_of_nodes+=1; 
			//free(temp);
			return;	
		}
		else{
			temp->link= list->head;
			list->head=temp;
			list->number_of_nodes+=1; 
			//free(temp);
			return;	
		
		}
	}
	
	struct Node* prev=list->head;
	for(int i=0;i<(position-1);i++){
		prev=prev->link;//address of prev node		
	}
	
	struct Node* next=list->head;
	for(int i=0;i<position;i++){
		next=next->link; //address of next node			
	}
	
	temp->link=next;
	prev->link=temp;
	list->number_of_nodes+=1; 
		
}

void list_reverse(List* list)
{
	struct Node* prev = NULL; 
	struct Node* cur = list->head;
	struct Node* next = NULL;
	
	while(cur!=NULL){
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	list->head=prev;	 	
}


