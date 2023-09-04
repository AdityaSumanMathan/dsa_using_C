//WAP to sort an array of integers using selection sort technique. [use functions]

#include<stdio.h>

void select_sort(int [], int);
void input(int [], int);
void display(int [], int);

void main()
{
    int arr[15], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    input(arr,n);
    select_sort(arr,n);
    printf("The array after selection sort:");
    display(arr,n);
}

void select_sort(int a[], int n)
{
    int i,j,k, temp;
    for(i=0; i<n; i++)
    {
        j=i;
        for(k= (i+1); k<n;k++)
        {
            if(a[k]< a[j])
            {
                j=k;
            }
            temp= a[i];
            a[i]= a[j];
            a[j]=temp;
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