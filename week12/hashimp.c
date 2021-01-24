#include "hash.h"
HashTable *create_table(int size)
{
    	HashTable *hashTable = malloc(size * sizeof(HashTable));
    	hashTable->table = malloc(size * sizeof(int));
    	hashTable->size = size;
    	for (int j = 0; j < size; j++)
    	{
        	hashTable->table[j] = -1;
    	}
    	return hashTable;
}

void insert(HashTable *htable, int element)
{
    	int value = element % (htable->size);
    	int k = value;
    	while (htable->table[value] != -1)
    	{
        	value++;
        	if (value == k)
        	{
            		return;
        	}
        	value %= htable->size;
    	}
    	htable->table[value] = element;
}

int search(HashTable *htable, int element)
{
    	int count = 0;
    	while (count < htable->size)
    	{

        	if (htable->table[count] == element)
        	{
            		return 1;
        	}
        	count++;
    	}		
    	return 0;
}

void delete (HashTable *htable, int element)
{
    	int count = 0;
    	while (count < htable->size)
    	{

        	if (htable->table[count] == element)
        	{
            		htable->table[count] = -1;
        	}
        	count++;
    	}
}

void destroy_table(HashTable *htable)
{
    	free(htable->table);
    	free(htable);
}
