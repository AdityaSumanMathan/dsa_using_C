// WAP to sort an array of integers using insertion sort technique. [use functions]

#include<stdio.h>
void insert_sort(int [], int);
void input(int [], int);
void display(int [], int);

int main()
{
    int arr[15], n;
    printf("Enter the number of elements int the array: ");
    scanf("%d", &n);
    input(arr,n);
    insert_sort(arr, n);
    printf("Array after insertion sort is:\n");
    display(arr,n);
    return 0;
}

void input(int a[], int n){
    int i;
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void insert_sort(int a[], int n){
    int i,j,k;
    int key;
    for(j=1; j<n; j++)
    {
        key= a[j];
        i=j-i;
        while(i>=0 && a[i>key]){
            a[i+1]= a[i];
            i--;
        }
        a[i+1]=key;
    }
}


void display(int a[], int n){
    printf("\n");
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}