#include "6b.h"
stack* stack_initialize(int size)
{
	stack* Stack_ptr=(stack*)malloc(sizeof(stack));
	Stack_ptr->top=-1;
	Stack_ptr->arr=(int*)malloc(size*sizeof(int));
	return Stack_ptr;
}

void stack_push(stack *ptr_stack, int key) 
{
	ptr_stack->arr[++(ptr_stack->top)]=key; //mistake was made in prefix and postfix
}

void stack_pop(stack *ptr_stack)
{
	(ptr_stack->top)--; //works both prefix and postfix
}

int stack_is_empty(stack *ptr_stack)
{
	if(ptr_stack->top==-1)
		return 1;
	return 0;
}

int stack_peek(stack *ptr_stack) 
{
	return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(stack *ptr_stack) 
{
	ptr_stack->top=0;
	ptr_stack->arr=NULL;
	free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
	stack* ptr_stack = stack_initialize(strlen(source_infix));
	
	int k=-1;
	for(int i=0;i<strlen(source_infix);i++)
	{	
		if((source_infix[i]>='A' && source_infix[i]<='Z')|| (source_infix[i]>='a' && source_infix[i]<='z'))
		{
			target_postfix[++k]=source_infix[i]; //postfix prefix error in k again :(
		}
		else if(source_infix[i]=='(' || source_infix[i]=='[' || source_infix[i]=='{')
		{
			stack_push(ptr_stack,source_infix[i]);
		}
		else if(source_infix[i]=='+' || source_infix[i]=='-')
		{
		
			while(stack_peek(ptr_stack)=='+' || stack_peek(ptr_stack)=='*' || stack_peek(ptr_stack)=='/' || stack_peek(ptr_stack)=='-')
			{
				target_postfix[++k]=stack_peek(ptr_stack);
				stack_pop(ptr_stack);		
			}
			
			stack_push(ptr_stack,source_infix[i]); 
			
		}
		else if(source_infix[i]=='/' || source_infix[i]=='*')
		{
			while(stack_peek(ptr_stack)=='*' || stack_peek(ptr_stack)=='/')
			{
				target_postfix[++k]=stack_peek(ptr_stack);
				stack_pop(ptr_stack);	
			}
			
			stack_push(ptr_stack,source_infix[i]); 
		}
		else if(source_infix[i]==')' || source_infix[i]==']' || source_infix[i]=='}')
		{
			switch(source_infix[i])
			{
				case ')':
					while(stack_peek(ptr_stack) !='(')
					{
						target_postfix[++k]=stack_peek(ptr_stack);
						stack_pop(ptr_stack);	
					}
					stack_pop(ptr_stack);
					break;
				
				case ']':
					while(stack_peek(ptr_stack) !='[')
					{
						target_postfix[++k]=stack_peek(ptr_stack);
						stack_pop(ptr_stack);	
					}
					stack_pop(ptr_stack);
					break;
					
				case '}':
					while(stack_peek(ptr_stack) !='{')
					{
						target_postfix[++k]=stack_peek(ptr_stack);
						stack_pop(ptr_stack);	
					}
					stack_pop(ptr_stack);
					break;
			
			}
		}
	}
	
	while(!stack_is_empty(ptr_stack))
	{
		target_postfix[++k]=stack_peek(ptr_stack);
		stack_pop(ptr_stack);
	}
	stack_destroy(ptr_stack);
	
}
