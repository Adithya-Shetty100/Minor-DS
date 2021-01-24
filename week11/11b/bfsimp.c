#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	//TODO
	int visited[n];
    	int queue[n];
    	int front = 0;
    	int rear = -1;
    	for (int a=0; a<n; a++)
    	{
        	visited[a] = 0;
    	}
    
    	queue[++rear] = v;
    	visited[v] = 1;
    
    	while (front <= rear)
    	{
        	int st = queue[front++];
        	if ( st == u )
        	{
            		return 1;
        	}
        	for (int i=0;i<n;i++)
        	{

            		if (graph[st][i] && !visited[i])
            		{

                		queue[++rear]=i;
               			visited[i]=1;
				
            		}
        	}
    	}
    	return 0;
}	
