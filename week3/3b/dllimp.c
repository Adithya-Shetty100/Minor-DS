#include"dll.h"
int count_nodes(List* dll)
{
	return dll->number_of_nodes;
	
}

void insert_front(List* dll, int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    
    if(dll->head!=NULL)
    {
    	temp->next=dll->head;
    	dll->head->prev=temp; 
    }
    
    dll->head=temp;
    dll->number_of_nodes+=1;   
}


void dllist_delete_beginning(List* list)
{
    if(list->head==NULL)
    {
    	return;
    }
    
    struct Node* last=list->head;
    if(last->next!=NULL)
    {
    	list->head=last->next;
	last->next=NULL;
	last=list->head;
	last->prev=NULL;
    }
    else{
    	list->head=NULL;
    }
    
    list->number_of_nodes-=1;
    
}


void position_delete(List* dll, int pos)
{
    if(pos>=dll->number_of_nodes)
    	return;
    
    struct Node* cur=dll->head; 
    struct Node* prev=NULL;
    struct Node* next=NULL;
    if(pos==0)
    {
    	next=cur->next;
    	if(next!=NULL)
    	{
	    	next->prev=dll->head;
	    	dll->head=next;
    	}
    }
    else
    {
    	for(int i=0;i<pos;i++)
    		cur=cur->next;
    	
	prev=cur->prev;
	next=cur->next;
	prev->next=next;
	if(next!=NULL)
		next->prev=prev;  
    }   
    
    cur->next=NULL;
    cur->prev=NULL;
    //cur->data=NULL;	

    dll->number_of_nodes-=1; 

}

int search_list(List* dll,int key)
{
    if(dll->head==NULL)
    	return -1;
    	
    struct Node* temp=dll->head;
    int i=0;
    while(temp!=NULL)
    {
    	if(temp->data==key)
    		return i;
    	i++;
	temp=temp->next;
    }  

    return -1;
    
}


void reverse_list(List* dll)
{
	struct Node* cur=dll->head; 
	struct Node* temp=NULL;
	
	if(cur->next==NULL)
		return;
	
	while(cur!=NULL)
	{
		temp=cur->prev;
		cur->prev=cur->next;
		cur->next=temp;
		cur=cur->prev;
	
	}
	
	if(temp!=NULL)
		dll->head=temp->prev;
  
}


