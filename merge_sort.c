#include <stdio.h>
#include <stdlib.h>
int arr[40];
void quick_sort(int,int);
int partition(int,int);
void swap(int *,int *);
int main() {
	int size,i;
	printf("\nEnter size of Array: ");
	scanf("%d",&size);
	printf("\nEnter elements of the Array:\n");
	for(i=0;i < size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nBefore Sorting:\n");
	for(i=0;i < size;i++)
	{
		printf("%d\t",arr[i]);
	}
	quick_sort(0,size-1);
	printf("\nAfter	sorting:\n");
	for(i=0;i < size;i++)
	{
		printf("%d\t\n",arr[i]);
	}
	return 0;
}
void quick_sort(int low,int high)
{
	int pi;
	if(low < high)
	{
		pi = partition(low,high);
		quick_sort(low,pi-1);
		quick_sort(pi+1,high);
	}
}
int partition(int low,int high)
{
	int i,j,pivot;
	i = low-1;
	pivot = arr[high];
	for(j=low;j <= high-1;j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return
		i+1;
}
void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
