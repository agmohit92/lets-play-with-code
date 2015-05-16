#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct AdjListNode{
	int dest;
	struct AdjListNode *next;
	int weigh;
}AdjListNode;

typedef struct AdjList{
	struct AdjListNode *head;
}AdjList;



typedef struct node{
	int V;
	//bool isExp;
	struct AdjList *array;
}Graph;


AdjListNode* newAdjListNode(int dest, int weigh)
{
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    newNode->weigh = weigh;
    return newNode;
}


Graph* createGraph(int V)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (AdjList*) malloc(V * sizeof(AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}

void addEdgeUnDirected(Graph* graph, int src, int dest, int weigh)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    AdjListNode* newNode = newAdjListNode(dest,weigh);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src,weigh);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void addEdgeDirected(Graph* graph, int src, int dest, int weigh)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    AdjListNode* newNode = newAdjListNode(dest,weigh);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
}

void printGraph(Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d(w=%d)", pCrawl->dest, pCrawl->weigh);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void push(int *stack, int val, int *top)
{
	*top = *top +1;
	stack[*top] = val;
}

int pop(int *stack, int *top)
{
	int r = stack[*top];
	*top = *top -1;
	return r;
}

void add(int *queue, int val, int *front)
{
	*front = *front +1;
	queue[*front] = val;
}

int deleteQ(int *queue, int *front, int *rear)
{
	int r;
	if(*front < *rear )
	return -1;
	r = queue[*rear];
	*rear = *rear +1;
	return r;
	
}

void BFS(Graph *graph, int v)
{
	int queue[20], front=-1,rear = 0;
	bool visited[20];
	add(&queue[0], v, &front);
	while(front >= rear)
	{
		v = deleteQ(&queue[0],&front,&rear);
		printf("%d\t",v );
		visited[v] = true;
		AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl)
        {
            v = pCrawl->dest;
            if(visited[v] == false)
            add(&queue[0], v, &front);
            pCrawl = pCrawl->next;
        }
        
		
	}
	
	
}

void DFS(Graph *graph, int v, bool *visited)
{
	if(visited[v]==true)
	return;
	
	visited[v]=true;
	AdjListNode* pCrawl = graph->array[v].head;
	printf("%d\t",v);
	
	while(pCrawl)
	{
		int r;
		r=pCrawl->dest;
		if(visited[r]==false)
		DFS(graph,r,&visited[0]);
		pCrawl = pCrawl->next;
	}
}

