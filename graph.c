#include "graph.h"
 
int main()
{
    // create the graph given in above fugure
    int V = 5,i;
    struct Graph* graph = createGraph(V);
    addEdgeDirected(graph, 0, 1,1);
    addEdgeDirected(graph, 0, 4,1);
    addEdgeDirected(graph, 1, 2,1);
    addEdgeDirected(graph, 1, 3,1);
    addEdgeDirected(graph, 1, 4,1);
    addEdgeDirected(graph, 2, 3,1);
    addEdgeDirected(graph, 3, 4,1);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
    for(i=0;i<V;i++)
    {
    	int j;
    	bool visited[20];
    	for(j=0;j<20;j++)
    	visited[j]=false;
    	
		BFS(graph, i);
    	printf("\n");
    	DFS(graph, i, &visited[0]);
    	printf("\n");
	}
 
    return 0;
}
