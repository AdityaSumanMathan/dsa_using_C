//WAP to PUSH(), POP(), PEEP(), CHANGE(), in a stack without using isFull() and isEmpty().

#include<stdio.h>
#define max 5
int s[max];
int top=-1;

void push(int item)
{
    if(top==max-1){
        printf("Stack Overflow\n");
    }
    else{
        top=top+1;
        s[top]=item;
    }
}

int pop()
{
    int item;
    if(top==-1){
        printf("Stack underflow\n");
        return 0;
    }
    item= s[top];
    top= top-1; //doubt
    return item;
}

int peep()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return s[top];
}

void change(int item, int pos)
{
    if(top==-1){
        printf("Underflow\n");
    }
    s[top-pos+1]= item; 
}

void display()
{
    int i;
    for(i=top; i>=0; i--)
    {
        printf("%d\t", s[i]);
    }
    printf("top=%d\n", top);
    printf("\n");
}

void main()
{
    int pos, i, ch, item;
    do{
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEP\n");
        printf("4.CHANGE\n");
        printf("5.DISPLAY\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 :printf("Enter item to insert: ");
                    scanf("%d", &item);
                    push(item);
                    break;
            case 2 :item=pop();
                    printf("Popped=%d\n",item);
                    break;
            case 3 :printf("The top element is:");
                    item=peep();
                    printf("%d", item);
                    break;
            case 4 :printf("Enter the value and pos");
                    scanf("%d %d", item, pos);
                    change(item, pos);
                    break;
            case 5 :display();
                    break;
            default: printf("Enter a valid choice.\n");

        }
    }while(ch!=6);
}