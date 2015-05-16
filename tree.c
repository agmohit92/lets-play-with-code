#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int val;
	struct node *left,*right;
}tree;

tree* createnode(int k)
{
	tree *newnode = (tree*)malloc(sizeof(tree));
	newnode->val =k;
	newnode->left = NULL;
	newnode->right = NULL;
	return(newnode);
}

tree* insertR(int k, tree* head)
{
	if(head == NULL)
	return(createnode(k));
	
	if(head->val > k)
	head->left = insertR(k,head->left);
	else
	head->right = insertR(k,head->right);
	return(head);
}

int search(tree *head,int k)
{
	if(head==NULL)
	return 0;
	if(head->val == k)
	return 1;
	if(head->val > k)
	return(search(head->left,k));
	return(search(head->right,k));
}

tree* minValueNode(tree* head)
{
	while(head->left != NULL)
	head = head->left;
	
	return(head);
}

tree* delete(int k, tree* head)
{
	if(head==NULL)
	return NULL;
	if(head->val > k)
	head->left = delete(k,head->left);
	else if(head->val < k)
	head->right = delete(k,head->right);
	
	else
	{
		if(head->left == NULL)
		{
			tree* temp = head;
			head = head->right;
			free(temp);
			return(head);
		}
		else if(head->right == NULL)
		{
			tree* temp = head;
			head = head->left;
			free(temp);
			return(head);
		}
		
		tree* temp = minValueNode(head->right);
		head->val = temp->val;
		head->right = delete(temp->val, head->right);
		return head;
	}
	return(head);
}

void insert1(int k,tree** head)
{
	tree* newnode;
	newnode = *head;
	if(*head==NULL){
	*head = createnode(k);
	return;
	}
	
	while(1)
	{
		if(newnode->val > k)
		{
			if(newnode->left == NULL)
			{
				newnode->left = createnode(k);
				return;
			}
			else
			newnode = newnode->left;
		}
		
		else
		{
			if(newnode->right == NULL)
			{
				newnode->right = createnode(k);
				return;
			}
			else
			newnode = newnode->right;
		}
		
		
	}
	return;
}

void inorder(tree *head)
{
	if(head == NULL)
	return;
	inorder(head->left);
	printf("%d\t",head->val);
	inorder(head->right);
}

void preorder(tree *head)
{
	if(head == NULL)
	return;
	
	inorder(head->left);
	inorder(head->right);
	printf("%d\t",head->val);
	
}

void postorder(tree *head)
{
	if(head == NULL)
	return;
	
	printf("%d\t",head->val);
	inorder(head->left);
	inorder(head->right);
}


int main()
{
	tree* head;
	head = '\0';
	int i,k;
	do
	{
		printf("Enter choice\n1.\tInsert\n2.\tprint\n3.\tInsertR\n4.\tsearch\n5.\tpreorder\n6.\tpostorder\n7.\tDelete\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("Enter value\n");
				scanf("%d",&k);
				insert1(k,&head);
				break;
			case 2:
				inorder(head);
				printf("\n");
				break;
			case 3:
				printf("Enter value\n");
				scanf("%d",&k);
				head = insertR(k,head);
				break;
			case 4:
				printf("Enter value\n");
				scanf("%d",&k);
				if(search(head,k))
				printf("found\n");
				else
				printf("not found\n");
				break;
			case 5:
				preorder(head);
				printf("\n");
				break;
			case 6:
				postorder(head);
				printf("\n");
				break;
			case 7:
				printf("Enter value\n");
				scanf("%d",&k);
				head = delete(k,head);
				break;
			default :
				break;	
		}
	}while(i<8 && i >0);
}
