#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
	//TODO	
	ptr_List = (List*) malloc(sizeof(List));
	ptr_List->head = NULL;
	ptr_List->number_of_Nodes = 0;
}

void List_insert_front(List* ptr_List, int data) 
{
	//TODO
	Node* ptr;	
	if(ptr_List->head!=NULL)
		ptr=create_Node(data,ptr_List->head);
	else
		ptr=create_Node(data,NULL);
		
	ptr_List->head=ptr;
	ptr_List->number_of_Nodes+=1; 
	return;		
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO
	if(Node_ptr != NULL)
	{
		return Node_ptr->data;
	}
}

void List_delete_front(List* ptr_List)
{
	//TODO
	Node* temp=(Node*)malloc(sizeof(Node));
	
	if(ptr_List->head!=NULL)
	{
		temp=ptr_List->head;
		ptr_List->head=temp->link;
		ptr_List->number_of_Nodes-=1; 
		free(temp);
		return;	
	}
}

void List_destroy(List* ptr_List) 
{
	//TODO
	Node *t, *u=NULL;
	t=ptr_List->head;
	while (t->link!=NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(ptr_List);
}


void stack_initialize(Stack *ptr_stack) 
{
	// TODO
	ptr_stack = (Stack*) malloc(sizeof(Stack));
	List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	// TODO
	List_insert_front(ptr_stack->ptr_List, key);
}

void stack_pop(Stack *ptr_stack) 
{
	// TODO
	List_delete_front(ptr_stack->ptr_List); 
}

int stack_is_empty(Stack *ptr_stack) 
{
	// TODO
	if(ptr_stack->ptr_List->head==NULL)
		return 1;
	else
		return 0;
}

const int stack_peek(Stack *ptr_stack)
{
	// TODO
	if(stack_is_empty(ptr_stack)==0 )
	{
		return Node_get_data(ptr_stack->ptr_List->head);
	}
	
	return 0;
}

void stack_destroy(Stack *ptr_stack) 
{
	// TODO
	List_destroy(ptr_stack->ptr_List);
	free(ptr_stack); 
}
				
int postfix_eval(const char* expression) 
{
    	// TODO
    	Stack ptr;
    	Stack* ptr_stack=&(ptr);
	List list;
	ptr_stack->ptr_List=&(list);
	stack_initialize(ptr_stack);
	
	int i=0;
	while(expression[i]!='\0')
	{
		
		if((expression[i]!='+') && expression[i]!='-' & expression[i]!='*' &  expression[i]!='/')
			stack_push(ptr_stack,expression[i]-'0');//convert char to int
		else
		{
			
			int a=stack_peek(ptr_stack);
			stack_pop(ptr_stack); 
			int b=stack_peek(ptr_stack);
			stack_pop(ptr_stack); 
			
			switch(expression[i])
			{
			
				case '+':
					stack_push(ptr_stack,a+b);
					break;
				case '-':
					stack_push(ptr_stack,b-a);
					//the first elemnt poped is second operand
					break;
				case '*':
					stack_push(ptr_stack,a*b);
					break;
				case '/':
					stack_push(ptr_stack,b/a);
					break;
			}
		}

		i++;
		
	}
	return stack_peek(ptr_stack); 
	
}
