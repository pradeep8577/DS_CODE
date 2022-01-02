#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int n)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=top;
	top=temp;
}
void pop()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("\nStack is empty\n");
		return ;
	}
	else{
	temp=top;
    top=top->next;
    free(temp);
	}
}
void display()
{
	struct node *temp=top;
	if(top==NULL)
	{
		printf("\nStack is empty\n");
		return;
	}
	printf("\nStack is\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int n,ch;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nEnter The Choice: ");
        scanf("%d",&ch);
    switch (ch)
    {
        case 1:
           printf("push the elment:");
           scanf("%d",&n);
           push(n);
           display(top);
           break;
        case 2:
           printf("pop the elemnt: ");  
           pop();
           display(top);
           break;
        case 3:
           display();
           break;  
        case 4:
           exit(0);
        default:
           break;
    }
    }
}