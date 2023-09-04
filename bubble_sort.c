//	WAP to sort an array of integers using bubble sort technique. Use the functions to input(), display() and bubble_sort(). 

#include<stdio.h>
void bubble_sort(int [], int);
void input(int [], int);
void display(int [], int);

void main()
{
    int arr[15], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    input(arr,n);
    bubble_sort(arr,n);
    printf("The array after bubble sort:");
    display(arr,n);
}

void bubble_sort(int a[], int n)
{
    int i,j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]> a[j+1])
            {
                temp= a[j];
                a[j]= a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void input(int arr[], int n)
{
    int i;
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n)
{
    printf("\n");
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}