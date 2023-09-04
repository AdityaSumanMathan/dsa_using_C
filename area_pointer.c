#include<stdio.h>

void area_peri(int , int , int *, int *);


void main()
{
    int a, b, area, peri;
    printf("Enter the length and breadth of the rectangle:\n");
    scanf("%d %d", &a, &b);
    area_peri(a,b, &area, &peri);
}

void area_peri(int l, int b, int *area, int *peri){
    *area= l*b;
    *peri= 2*(l+b);
    printf("\nAREA= %d", *area);
    printf("\nPERIMETER= %d", *peri);
}