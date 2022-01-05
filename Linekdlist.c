#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *next;
};
struct node *head=NULL;

void ins_at_start(int data)
{
      struct node *temp;
      temp=(struct node*)malloc(sizeof(struct node));
      temp->data=data;
      temp->next=head;
      head=temp;
}

void ins_at_end(int data)
{
        struct node *temp,*p;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            return;
        }
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
}

void del_at_start()
{
      if(head==NULL)
      {
            printf("list is empty");
            return ;
      }
      struct node *temp=head;
      head=head->next;
      free(temp);
}

void del_at_end()
{
      if (head==NULL)
      {
            printf("list is empty");
            return ;
      }
      struct node *temp=head;
      while(temp->next->next != NULL)
      {
            temp=temp->next;
      }
      free(temp->next);
      temp->next=NULL;
}

void display()
{
      if(head==NULL)
      {
            printf("List is Empty");
            return ;
      }
      struct node *temp=head;
      while(temp != NULL)
      {
            printf("%d ",temp->data);
            temp=temp->next;
      }
      printf("\n");  
}

int main()
{
      int choice,data,position;
      while(1)
      {
            printf("\n1.insert at beignning\n2.insert at end\n3.Delete at Start\n4.Delete at End\n5.Display\n5.Exit\n");
            printf("\nEnter The Choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                  case 1:
                     printf("Enter the data:");
                     scanf("%d",&data);
                     ins_at_start(data);
                     break;
                  case 2:
                     printf("Enter The data:");
                     scanf("%d",&data);
                     ins_at_end(data);
                     break;
                  case 3:
                     del_at_start(data);
                     break; 
                  case 4:
                     del_at_end(data);
                     break; 
                  case 5:
                     display();
                     break;
                  case 6:
                      exit(0);       
            }
      }
  return 0;
}
