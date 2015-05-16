#include <stdlib.h>


typedef struct node {
	struct node *right;
	struct node *left;
	int key, height;
} AVL_node;

int height(AVL_node *node)
{
	if(node==NULL)
	return 0;
	return node->height;
}

int max(int a, int b)
{
	return (a>b) ? a : b;
}

AVL_node* newNode(int key)
{
	AVL_node* temp = (AVL_node*)malloc(sizeof(AVL_node));
	temp->key = key;
	temp->right = NULL;
	temp->left = NULL;
	temp->height = 1;
	
	return temp;
}

/*
			x								y
		   / \							   / \
		  y  T4                          z	   x
		 / \			------>         / \   / \
		z  T3						   T1 T2 T3 T4
	   / \
	  T1 T2
*/
AVL_node* rightrotate(AVL_node *x)
{
	AVL_node *y = x->left;
	AVL_node *T3 = y->right;
	
	y->right = x;
	x->left = T3;
	
	y->height = max(height(y->left), height(x->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	
	return y;
}

/*
  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4
*/


AVL_node* leftrotate(struct node *z)
{
    AVL_node *y = z->right;
    AVL_node *T2 = y->left;
 
    y->left = z;
    z->right = T2;
 
    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}


AVL_node* insert_AVL(AVL_node *node,int key)
{
	if(node == NULL)
	return newNode(key);
	
	if(node->key > key)
	node->left = insert_AVL(node->left, key);
	else
	node->right = insert_AVL(node->right, key);
	
	node->height = max(height(node->left), height(node->right)) +1;
	
	int balance = height(node->left) -  height(node->right);
	
	if(balance > 1 && node->left->key > key)
	return rightrotate(node);
	
	if(balance > 1 && node->left->key < key)
	{
		node->left = leftrotate(node->left);
		return rightrotate(node);
	}
	
	if(balance < -1 && node->right->key < key)
	return leftrotate(node);
	
	if(balance < -1 && node->right->key > key)
	{
		node->right = rightrotate(node->right);
		return leftrotate(node);
	}
	
	return node;
}

AVL_node* minValueNode(AVL_node* root)
{
	AVL_node * temp = root;
	while(temp->left != NULL)
	temp=temp->left;
	
	return temp;
}

AVL_node* delete_AVL(int key, AVL_node* root)
{
	if(root==NULL)
	return NULL;
	if(root->key > key)
	root->left = delete_AVL(key,root->left);
	else if(root->key < key)
	root->right = delete_AVL(key,root->right);
	
	else
	{
		if(root->left == NULL)
		{
			AVL_node* temp = root;
			root = root->right;
			free(temp);
			return(root);
		}
		else if(root->right == NULL)
		{
			AVL_node* temp = root;
			root = root->left;
			free(temp);
			return(root);
		}
		
		AVL_node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = delete_AVL(temp->key, root->right);
		return root;
	}
	if (root == NULL)
      return root;
 
    root->height = max(height(root->left), height(root->right)) + 1;
 
    int balance = height(root->left) - height(root->right);
 
    if (balance > 1 && height(root->left->left) - height(root->left->right) >= 0)
        return rightrotate(root);
 
    if (balance > 1 && height(root->left->left) - height(root->left->right) < 0)
    {
        root->left =  leftrotate(root->left);
        return rightrotate(root);
    }

    if (balance < -1 && height(root->right->left) - height(root->right->right) <= 0)
        return leftrotate(root);
 
    if (balance < -1 && height(root->right->left) - height(root->right->right) > 0)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
 
    return root;
	
}

void inorder(AVL_node *root)
{
	if(root == NULL)
	return;
	inorder(root->left);
	printf("%d\t",root->key);
	inorder(root->right);
}

AVL_node* createSample()
{
	int arr[10] = {6,4,1,8,78,23,2,0,67,99};
	int i=0;
	AVL_node* root = '\0';
	for(i=0;i<10;i++)
	root = insert_AVL(root, arr[i]);
	return root;
}

int main()
{
	AVL_node* root;
	root = createSample();
	inorder(root);
	root = delete_AVL(23, root);
	inorder(root);
	
}

