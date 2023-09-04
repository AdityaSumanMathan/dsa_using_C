//WAP to compute factorial of a number using pointer.

#include<stdio.h>
 
void fact(int,int *);
int main(){
  int i,factorial,n;
  printf("Enter a number: ");
  scanf("%d",&n);
  fact(n,&factorial);
  return 0;
}
 
void fact(int n,int *fact){
    int i;
    *fact =1;
    for(i=1;i<=n;i++){
        *fact=*fact*i;
    }
    printf("Factorial of %d is: %d",n,*fact);
}