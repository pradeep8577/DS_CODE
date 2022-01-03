#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top=-1;
void push(int );
void pop();
void display();
void main()
{
    int ch,x;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.quit");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data:");
                   scanf("%d",&x);
                   push(x);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                break;
            default:printf("Invalid choice");
        }
    }
}
void push(int n)
{
    if(top==size-1)
    {
        printf("Stack is overflow\n");
    }
    else{
        top++;
        stack[top]=n;
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack is underflow\n");
    }
    else{
        item=stack[top];
        top--;
        printf("%d\n",item);
    }
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
