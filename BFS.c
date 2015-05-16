#include "tree.h"
//#define MAX 20;




tree* createSample()
{
	int arr[10] = {6,4,1,8,78,23,2,0,67,99};
	int i=0;
	tree* root = '\0';
	for(i=0;i<10;i++)
	root = insertR(arr[i], root);
	return root;
}

int main()
{
	tree* root;
	root = createSample();
	inorder(root);
	BFS(root);
	printf("\n");
	DFS(root);
}
