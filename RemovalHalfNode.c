//given-a-binary-tree-how-do-you-remove-all-the-half-nodes
#include "tree.h"

tree* createSample()
{
	int arr[10] = {6,4,1,8,78,23,2,0,67,99};
	int i=0;
	tree* root = '\0';
	for(i=0;i<10;i++)
	root = insertR(arr[i], root);
	return root;
}

tree* RemoveHalfNode(tree *root)
{
	if(root==NULL)
	return NULL;
	
	root->left = RemoveHalfNode(root->left);
	root->right = RemoveHalfNode(root->right);
	
	if(root->left == NULL && root->right == NULL)
	return root;
	
	if(root->left == NULL)
	{
		tree *temp = root->right;
		free(root);
		return temp;
	}
	
	if(root->right == NULL)
	{
		tree *temp = root->left;
		free(root);
		return temp;
	}
	
	return root;
}

int main()
{
	tree* root = createSample();
	inorder(root);
	printf("\n");
	root = RemoveHalfNode(root);
	inorder(root);
}
