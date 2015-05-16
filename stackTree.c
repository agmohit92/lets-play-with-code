#include "tree.h"



int main()
{
	tree* stack[20];
	int top =0,i,k;
	tree *popItem = '\0';
	do
	{
		printf("Enter choice\n1.\tpush\n2.\tpop\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				if(top==25)
				{
					printf("Full\n");
					break;
								}				
				printf("Enter value\n");
				scanf("%d",&k);
				push(&stack[0], createnode(k), &top);
				break;
			case 2:
				if(top==0)
				{
					printf("empty\n");
					break;
								}	
				popItem = pop(&stack[0],&top);
				printf("%d\n",popItem->val);
				break;
			default:
				break;
				
		}
	}while(i<3 && i>0);
}
