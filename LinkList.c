#include <stdlib.h>


typedef struct node 
{
	int val;
	struct node *next;
} node;

node* findloc(int k, node *start)
{
	if(start == NULL)
	return '\0';
	
	if(start->val > k)
	return '\0';
	
	node *prevptr, *ptr;
	prevptr =start;
	ptr = start->next;
	
	while(ptr != NULL)
	{
		if(ptr->val > k)
		return(prevptr);
		else
		{
			prevptr = ptr;
			ptr = ptr->next;
		}
	}
	return(prevptr);
	
}


node* insert(node *start, int k)
{
	node *loc;
	loc = findloc(k,start);
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->val = k;
	if(loc == NULL)
	{
		newnode->next = start;
		start = newnode;
	}
	else
	{
		newnode->next = loc->next;
		loc->next = newnode;
	}
	return start;
}

node* delete(int k,node* start)
{
	if(start==NULL)
	return start;
	if(start->val==k)
	{
		node* temp;
		temp = start;
		start = start->next;
		temp->next = '\0';
		free(temp);
		return start;
	}
	else
	{
		node *prevptr,*ptr;
		prevptr = start;
		ptr = start->next;
		while(ptr!= NULL)
		{
			if(ptr->val == k)
			{
				prevptr->next = ptr->next;
				ptr->next = '\0';
				free(ptr);
				return start;
			}
			else
			{
				prevptr = ptr;
				ptr = ptr->next;
			}
		}
	}
}

void printlist(node *start)
{
	node *p;
	for(p=start; p!=NULL; p=p->next)
		printf("%d",p->val);
		printf("\n");
}

int main()
{
	node *start;
	int i=0,k;
	start = '\0';
	
	while(i!=4){
		printf("\nEnter\n1.\tInsert\n2.\tDelete\n3.\tprint\n4.Exit\t\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1 : 
			printf("\nEnter number\n");
			scanf("%d",&k);
			start = insert(start,k);
			break;
			case 2 :
			printf("\nEnter number\n");
			scanf("%d",&k);
			start = delete(k,start);
			break;
			case 3:
			printlist(start);
			break;
			case 4 :
			break;
			default :
				break;
				
		
		}
	}
	
}
