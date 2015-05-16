#include <stdlib.h>
//#include <alloc.h>

void swap(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	return;
}
int* BubbleSort (int* a, int n)
{
	int i,j,count;
	while(1)
	{
		count = 0;
		for(j=1,i=0; j<n; j++,i++)
		{
			if(a[i]>a[j])
			{
				count++;
				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
				
			}
		}
		if(count == 0)
		break;
	}
	return &a[0];
}


int* SelectionSort(int*a, int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
		if(a[i]>a[j])
		swap(&a[i],&a[j]);
	}
	return &a[0];
}

int* InsertionSort(int *a, int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp = i;
		while(temp>0 && a[temp]<a[temp-1])
		{
			swap(&a[temp], &a[temp-1]);
			temp--;
		}
		
	}
	return a;
}

int partition(int *a, int q,int r)
{
	int i,j;
	i=q;j=r;
	
	while(i<j)
	{
		while(a[i] <= a[q] && i<=r) i++;
		while(a[j] > a[q]) j--;
		if(i<j) 
		swap(&a[i],&a[j]);		
	}
	swap(&a[q], &a[j]);
	return j;	

}

void QuickSort(int* a, int q,int r)
{
	if(q<r)
	{
		int p = partition(&a[0], q,r);
		QuickSort(&a[0],q,p-1);
		QuickSort(&a[0],p+1,r);
	}
	
}


void merge(int* arr, int low,int mid,int high)
{
	int *temp;
	temp = (int *)malloc((high-low + 1)*sizeof(int));
	int l,i,m,k;
	l=low;i=0;
	m=mid+1;
	
	while(l<=m && m<=high)
	{
		if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
	}
	if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    for(k=low,l=0;k<=high&&l<i;k++,l++){
         arr[k]=temp[l];
    }
    free(temp);
}

void mergeSort(int *a, int low, int high)
{
	
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		mergeSort(&a[0],low,mid);
		mergeSort(&a[0],mid+1,high);
		merge(&a[0],low,mid,high);
	}
}

int main()
{
	int* A;
	int n =5,i,j;
	printf("Enter value of length\n");
	scanf("%d",&n);
	A = (int*)malloc(n*sizeof(int));
	if(A=='/0')
	printf("Error");
	else{
		printf("Enter values\n");
		//A[1]=1;A[2]=5;A[3]=2;A[4]=3;A[0]=4;
		for(i=0;i<n;i++)
		scanf("%d",&A[i]);
		
		//printf("value %d\n", partition(&A[0],0,n-1));
	mergeSort(&A[0],0,n-1);
	for(i=0;i<n;i++)
	printf("%d\t",A[i]);
	}
	
	
	return 1;
}
