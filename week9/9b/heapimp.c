#include "heap.h"
heap* heap_construct(int n)
{
    	heap* tmp=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    	tmp->capacity=n;
    	tmp->size=0;
    	tmp->elements[0] = 0;
    	return(tmp);
}

void heap_destruct(heap* tmp)
{
    	//TODO
    	free(tmp);
}

int heap_get_capacity(heap* tmp)
{
    	//TODO
    	return tmp->capacity;
}

int heap_get_size(heap* tmp)
{
    	//TODO
    	return tmp->size;
}

int heap_insert(heap* tmp,int data)
{
    	//TODO
    	if (tmp->size < tmp->capacity)
        	tmp->elements[++(tmp->size)] = data;
	else
        	return 0;
	int cur = tmp->size;
	while (cur && (data < tmp->elements[cur/2]))
    	{
		tmp->elements[cur] = tmp->elements[cur/2];
		tmp->elements[cur/2] = data;
		cur /= 2;
	}
	return 1;
}

int heap_get_min(heap* tmp)
{
    	//TODO
    	return tmp->elements[1];
}

void heap_remove(heap* tmp)
{
    	//TODO
    	tmp->elements[1] = tmp->elements[(tmp->size)--];
	int temp, min, cur = 1;
	while (2*cur <= tmp->size)
    	{
		min = (tmp->elements[2*cur] < tmp->elements[2*cur+1]) ? 2*cur : 2*cur+1;
		if (tmp->elements[cur] > tmp->elements[2*cur] || tmp->elements[cur] > tmp->elements[2*cur+1])
            	{
                	temp = tmp->elements[min];
                	tmp->elements[min] = tmp->elements[cur];
                	tmp->elements[cur] = temp;
                	cur = min;
            	}
		else break;
	}
}
























