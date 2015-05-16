#include <stdlib.h>

int parent(int iNode)
{
	if(iNode==0)
	return -1;
	return(iNode/2);
}

void heapify(int *heap, int position)
{
	if(heap==NULL)
	return;
	
	if(position == 0)
	return;
	
	int i = parent(position);
	if(heap[position] < heap[i])
	{
		int temp = heap[i];
		heap[i] = heap[position];
		heap[position]=temp;
		heapify(&heap[0], i);
	}
	return;
	
}

int insert(int *heap, int val, int k)
{
	int i;
	heap[k] = val;
	heapify(&heap[0], k);
	//for(i=0;i<k+1;i++)
	//printf("%d\t", heap[i]);
	//printf("\n");
	return k+1;
}

void extract_min(int *heap, int position, int k)
{
	int child1,child2;
	child1 = 2*position +1;
	child2 = 2*position +2;
	if(child1 > k)
	return;
	
	if(child2 > k && heap[position] > heap[child1])
	{
		int temp = heap[child1];
		heap[child1] = heap[position];
		heap[position] = temp;
		return;
	}
	if(heap[child1] >= heap[position] && heap[child2] >= heap[position])
	return;
	
	if(heap[child1] < heap[child2]  && heap[child1]< heap[position])
	{
		int temp = heap[child1];
		heap[child1] = heap[position];
		heap[position] = temp;
		extract_min(&heap[0], child1, k);
	}
	else
	{
		int temp = heap[child2];
		heap[child2] = heap[position];
		heap[position] = temp;
		extract_min(&heap[0], child2, k);
	}
	return;
	
}

int main()
{
	int i=0,j=0,heap[30];
	printf("insert value to insert in heap\n");
	scanf("%d",&i);
	while(i>=0)
	{
		j = insert(&heap[0],i,j);
		scanf("%d",&i);
	}
	
	for(i=0;i<j;i++)
	printf("%d\t", heap[i]);
	printf("\n");
	
	for(i=j-1;i>0;i--)
	{
		printf("%d\t", heap[0]);
		heap[0] = heap[i];
		extract_min(&heap[0], 0, i-1);
	}
	
	printf("%d\n", heap[0]);
	
	
}
