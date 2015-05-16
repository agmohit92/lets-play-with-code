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

tree* minValueNode(tree* head)
{
	while(head->left != NULL)
	head = head->left;
	
	return(head);
}

tree* delete1(int k, tree* head)
{
	if(head==NULL)
	return NULL;
	if(head->val > k)
	head->left = delete1(k,head->left);
	else if(head->val < k)
	head->right = delete1(k,head->right);
	
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
		head->right = delete1(temp->val, head->right);
		return head;
	}
	return(head);
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

void push(tree **stack, tree *node, int *top)
{
	stack[*top] = node;
	*top = *top + 1;
	
}

tree* pop(tree **stack, int *top)
{
	*top = *top -1;
	return(stack[*top]);
}

void add(tree **queue, tree *node, int *front)
{
	queue[*front]=node;
	*front += 1;
}

tree* deleteQ(tree **queue, int *front, int *rear)
{
	*rear += 1;
	return(queue[*rear]);
	
}

void BFS(tree *root)
{
	int front=0,rear=-1;
	tree *temp,*Queue[20];
	if(root==NULL)
	return;
	add(&Queue[0], root, &front);
	while(front-1!=rear)
	{
		temp = deleteQ(&Queue[0], &front, &rear);
		if(temp->left) add(&Queue[0], temp->left, &front);
		if(temp->right) add(&Queue[0], temp->right, &front);
		printf("%d\t", temp->val);
	}
	return;
}

void DFS(tree *root)
{
	int top=0;
	tree *Stack[20], *temp;
	if(root==NULL)
	return;
	push(&Stack[0], root, &top);
	while(top!=0)
	{
		temp = pop(&Stack[0], &top);
		if(temp->right) push(&Stack[0], temp->right, &top);
		if(temp->left) push(&Stack[0], temp->left, &top);
		printf("%d\t",temp->val);
	}
	return;
	
}
