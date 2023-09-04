// WAP to check whether the entered matrix is sparse or not!

#include<stdio.h>
void check_sparse(int m[10][10], int , int);


void check_sparse(int m[10][10], int r, int c)
{
    int i, j, size, count=0;
    size= r*c;

    for(i=0; i<r; i++){
        for(j=0; j<c; j++)
        {
            if(m[r][c]==0){
                count++;
            }
        }
    }
    if(count>(size/2))
    {
        printf("The entered matrix is a sparse matrix.\n");
    }
    else{
        printf("Not a sparse matrix.\n");
    }
}

void main()
{
    int i,j, r, c, m[10][10];
    printf("Enter the number of rows and columns : ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements of the matrix:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    check_sparse(m,r,c);
}