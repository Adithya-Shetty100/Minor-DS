#include "5a.h"
#include <string.h>

static Node* create_Node(int data, Node* link) //c
{
	// TODO - create and allocate dynamic space
	Node* new=(Node*)malloc(sizeof(Node));
	new->data=data;
	new->link=link;
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
	// give address of
	//Node_ptr=(struct Node*)malloc(sizeof(struct Node));
	// //p=ptr_list->head;
	if(Node_ptr != NULL)
	{
		// //Node_ptr->data=ptr_list->head->data;
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
	//ptr_Stack = (Stack*) malloc(sizeof(Stack));
	printf("%s","c9a\n");
	//ptr_Stack->ptr_list=(List*) malloc(sizeof(List));
	list_initialize(ptr_Stack->ptr_list);
	printf("%s","c9b\n");
	//ptr_Stack->ptr_list=(List)
	
	//ptr_Stack->ptr_list->head = NULL;
	//ptr_Stack->ptr_list->number_of_Nodes=0;
	printf("%s","c9c\n");
	
	
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
		return ptr_Stack->ptr_list->head->data;
	}
	
	return 0;
}

void Stack_destroy(Stack *ptr_Stack)
 {
	//TODO	- deallocate
	
	list_destroy(ptr_Stack->ptr_list);
	free(ptr_Stack); 
	
	/* List *t, *u=NULL;
	t=ptr_Stack->ptr_list;
	while (t->link!=NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(ptr_Stack);*/
}

int match_parenthesis(const char* string)
{
	//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
	List* ptr_list=(List*) malloc(sizeof(List));
	Stack* ptr_Stack= (Stack*) malloc(sizeof(Stack));
	list_initialize(ptr_list); 
	Stack_initialize(ptr_Stack);
	//ptr_stack->list
	printf("%s","c1\n"); //c
	
	for(int i=strlen(string)-1;i>=0;i--)
	{
		list_insert_front(ptr_list, string[i]);
	
	}
	printf("%s","c2\n"); //c
	
	while(ptr_list->head!=NULL)
	{
		char c=Node_get_data(ptr_list->head);
		list_delete_front(ptr_list);
		printf("%s","c3\n"); //c
		
		if(c=='[' || c=='{' || c=='(')
		{
			printf("%s","c4a\n"); //c
			Stack_push(ptr_Stack, c);
			printf("%s","c4\n"); //!!!	
		}
		else
		{
			if(Stack_peek(ptr_Stack)==c)
			{
				printf("%s","c5\n");
				Stack_pop(ptr_Stack);
				printf("%s","c6\n");
			}
			else
				return 0;
		}
	
	}
	
	
	if(Stack_is_empty(ptr_Stack)==0 )
	{
		printf("%s","c7\n");
		return 0;
	}
	else
		return 1;
	
	
}	

/*
//List* ptr_list=(List*) malloc(sizeof(List));
	//list_initialize(ptr_list); 
	
	
	//int d=Node_get_data(ptr_list->head);
	
	
	struct Node *new=create_Node(key,NULL);
	printf("%s","c8a\n");//c
	
	struct List* header=ptr_Stack->ptr_list;
	//header->hea
	//list_initialize(ptr_Stack->ptr_list);
	printf("%s","c8b\n");//!!
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	header->number_of_Nodes+=1; 
	printf("%s","c8c\n");
	
	if(ptr_Stack->ptr_list->head==NULL)
	{
		ptr_Stack->ptr_list->head=new;
		printf("%s","c8d\n");
		return;
	}
	
	temp=ptr_Stack->ptr_list->head;
	ptr_Stack->ptr_list->head=new;
	ptr_Stack->ptr_list->head->link=temp;
	printf("%s","c8e\n");
*/
 

