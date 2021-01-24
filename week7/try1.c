#include "queue.h"
static node *create_node(int id, int time, node *link) //c
{
	struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    	temp->id = id; 
    	temp->time = time; 
    	temp->link = NULL; 
    	return temp; 
	
}


void list_initialize(List *ptr_list) //c
{
	ptr_list = (List*) malloc(sizeof(List));
	ptr_list->head = NULL;
	ptr_list->tail = NULL;
	ptr_list->number_of_nodes = 0;
}


const int node_get_id(node *node_ptr) //c
{
	return node_ptr->id;
	
}

const int node_get_time(node *node_ptr)  //c
{
  	return node_ptr->time;
}


void list_insert_rear(List *ptr_list, int id, int time) //c
{
	
	struct node* temp = create_node(id, time, NULL); 

    	if (ptr_list->tail == NULL) { 
        	ptr_list->head = ptr_list->tail = temp; 
        	ptr_list->number_of_nodes+=1;
        	return; 
    	} 

    	ptr_list->tail->link= temp; 
    	ptr_list->tail = temp;
    	ptr_list->number_of_nodes+=1; 
	//printf("%s","1a");	
}


void list_delete_front(List *ptr_list)
{
    	struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    	temp=ptr_list->head; 
    	
    	if(temp==NULL)
    	{
    		return;
    	}
    	else
    	{
    		if(ptr_list->head==ptr_list->tail)
    		{
    			ptr_list->head=NULL;
    			ptr_list->tail=NULL;
    		}
    		else
    		{
    			ptr_list->head=ptr_list->head->link;
    		}
    		
    		ptr_list->number_of_nodes-=1;
    		free(temp);
    	
    	}

}


void list_destroy(List *ptr_list)
{
	node *t, *u=NULL;
	t=ptr_list->head;
	while (t->link!=NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(ptr_list);
}


void queue_initialize(Queue *queue_list) //c 
{

	queue_list = (Queue*) malloc(sizeof(Queue));
	list_initialize(queue_list->ptr_list);
	//printf("%s","6a");
}


void queue_enqueue(Queue *ptr, int id, int time) //c
{
	list_insert_rear(ptr->ptr_list, id, time);
	
}

void queue_dequeue(Queue *ptr)
{
	list_delete_front(ptr->ptr_list);
}


int queue_is_empty(Queue *ptr)
{
	printf("%s","4a");
	if(ptr->ptr_list->tail==NULL)
		return 0;
	return 1;	
}


void queue_peek(Queue *ptr)
{
	if(queue_is_empty(ptr)==0)
	{
		printf("%s","Empty Queue");
	}
	else
	{
		printf("%d",node_get_id(ptr->ptr_list->head));
		printf("%d",node_get_time(ptr->ptr_list->head));
	}
	
}


void queue_destroy(Queue *ptr)
{
	list_destroy(ptr->ptr_list);
	free(ptr); 	
}


const int queue_find_person(Queue *ptr_queue, int t)
{
	/*if(queue_is_empty(ptr)==1)
	{
		//printf("%s","5a");
		printf("%s","Empty Queue");
		return;
	}*/
	
	/*struct node* next = (struct node*)malloc(sizeof(struct node));
	struct node* last = (struct node*)malloc(sizeof(struct node));
	int time=0;
	int id=0;
	
	while(time<t && temp!=NULL)
	{
		temp=ptr_queue->ptr_list->head;
		time+=temp->time;
		id=
	}*/
		
		
		
	
	
	
}



