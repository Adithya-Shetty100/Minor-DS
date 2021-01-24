#include "5a.h"
#include <string.h>

static Node* create_Node(int data, Node* link) //c
{
	// TODO - create and allocate dynamic space
	Node* new=(Node*)malloc(sizeof(Node));
	new->data=data;
	new->link=link;
	return new;
}


void list_initialize(List* ptr_list) //c
{
	//TODO - initialize structure members to default values
	ptr_list = (List*) malloc(sizeof(List));
	ptr_list->head = NULL;
	ptr_list->number_of_Nodes = 0;
}


void list_insert_front(List* ptr_list, int data) //c
{
	//TODO - perform linked list implementation of push operation.
	Node* ptr;	
	if(ptr_list->head!=NULL)
		ptr=create_Node(data,ptr_list->head);
	else
		ptr=create_Node(data,NULL);
		
	ptr_list->head=ptr;
	ptr_list->number_of_Nodes+=1; 
	return;	
}


const int Node_get_data(Node *Node_ptr) //c
{
	//TODO - return the top most element
	if(Node_ptr != NULL)
	{
		return Node_ptr->data;
	}
}


void list_delete_front(List* ptr_list) //c
{
	//TODO - perform linked list implementation of pop operation.
	Node* temp=(Node*)malloc(sizeof(Node));
	
	if(ptr_list->head!=NULL)
	{
		temp=ptr_list->head;
		ptr_list->head=temp->link;
		ptr_list->number_of_Nodes-=1; 
		free(temp);
		return;	
	}
	

}


void list_destroy(List* ptr_list) 
{
	//TODO - free the allocated space
	Node *t, *u=NULL;
	t=ptr_list->head;
	while (t->link!=NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
	//TODO - get the memory allocation for stack, and intern call list initialize
	ptr_Stack = (Stack*) malloc(sizeof(Stack));
	list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
	//TODO	 - call the function list_insert_front	
	list_insert_front(ptr_Stack->ptr_list, key); 
	 

}

void Stack_pop(Stack *ptr_Stack) 
{
	//TODO- call the function list_delete_front
	list_delete_front(ptr_Stack->ptr_list); 
	
}

int Stack_is_empty(Stack *ptr_Stack) 
{
	//TODO	- return 0 if stack is not empty
	if(ptr_Stack->ptr_list->head==NULL)
		return 1;
	else
		return 0;
	
}

const int Stack_peek(Stack *ptr_Stack) 
{
	//TODO	- return the top most element of the stack
	
	if(Stack_is_empty(ptr_Stack)==0 )
	{
		return Node_get_data(ptr_Stack->ptr_list->head);
	}
	
	return 0;
}

void Stack_destroy(Stack *ptr_Stack)
 {
	//TODO	- deallocate
	
	list_destroy(ptr_Stack->ptr_list);
	free(ptr_Stack); 
}

int match_parenthesis(const char* string)
{
	//TODO - implement the code to match paranthesis in a string which is passed as a parameter.

	Stack ptr;
	Stack* ptr_Stack=&(ptr);
	List list;
	ptr_Stack->ptr_list=&(list);
	Stack_initialize(ptr_Stack);
	

	int i=0;

	while(string[i]!='\0')
	{
		
		if(string[i]=='[' || string[i]=='{' || string[i]=='(')
		{
			Stack_push(ptr_Stack,string[i]);	
		}
		else
		{
			if(string[i]==']')
			{
				if(Stack_peek(ptr_Stack)=='[')
				{
				Stack_pop(ptr_Stack);
				
				}
				else
					return 0;
			}
			else if(string[i]=='}')
			{
				if(Stack_peek(ptr_Stack)=='{')
				{
				Stack_pop(ptr_Stack);
				
				}
				else
					return 0;
			}
			else if(string[i]==')')
			{
				if(Stack_peek(ptr_Stack)=='(')
				{
				Stack_pop(ptr_Stack);
				
				}
				else
					return 0;
			}
			
			
		}
		
		i++;
	
	}
	
	
	if(Stack_is_empty(ptr_Stack)==0 )
	{
		return 0;
	}
	else
		return 1;
	
	
}
