#include <stdio.h>
#include <stdlib.h>
int    a[100],arr[100];
void merge_sort(int low,int high)
{
	int mid;
	if(low < high)
	{
		mid = (low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,high,mid);
	}
	else
	{
		return;
	}
}
void merge(int low,int high,int mid)
{
	int i,j,k;
	for(i = low,j = mid+1,k = low;i <= mid && j <= high;k++)
	{
		if(a[i] <= a[j])
		{
			arr[k] = a[i];
			i++;
		}
		else
		{
			arr[k] = a[j];
			j++;
		}
	}
	while(i <= mid)
	{
		arr[k] = a[i];
		k++;
		i++;
	}
	while(j <= high)
	{
		arr[k] = a[j];
		k++;
		j++;
	}
	for(i=low;i <= high;i++)
	{
		a[i] = arr[i];
	}
}
int main() 
{
	int size,i;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	printf("\nEnter elements of the array:\n");
	for(i=0;i < size;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe array before Sorting:\n");
	for(i=0;i < size;i++)
	{
		printf("%d\t",a[i]);
	}
	merge_sort(0,size-1);
	printf("\nThe array after sorting:\n");
	for(i=0;i < size;i++)
	{
		printf("%d\t\n",a[i]);
	}
	return 0;
}