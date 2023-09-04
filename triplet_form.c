//Convert the sparse matrix into its triplet form.

#include<stdio.h>
#define x 10
#define y 10

void display_spm(int spm[][3], int r, int c){
    int i, j;
    printf("The triplet for of the sparse matrix is:\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d\t", spm[i][j]);
        }
    }
    printf("\n");
}

void sparse_triplet(int m[][10], int r, int c,int spm[][3]){
    int i,j,k=1, count=0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(m[i][j]!=0)
            {
                spm[k][0]=i;
                spm[k][1]=j;
                spm[k][2]=m[i][j];
                k++;
                count++;
            }
        }
    }
    spm[0][0]=r;
    spm[0][1]=c;
    spm[0][2]= count;
    display_spm(spm, count+1,3);
}
void main()
{
    int i,j, m[10][10], r,c,spm[x][3];
    printf("Enter the number of rows and columns of the sparse matrix:\n");
    scanf("%d %d", &r, &c);
    printf("Enter the elements of the sparse matrix:\n ");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    sparse_triplet(m, r,c,spm);
}