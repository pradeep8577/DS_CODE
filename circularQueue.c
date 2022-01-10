#include <stdio.h>
#include <stdlib.h>
#define Max_size 5
struct queue
{
    int a[Max_size];
    int rare;
    int front;
};
void InqueueData(int data,struct queue *ptr);
void Display(struct queue ptr);
int Dequeue(struct queue *ptr);
int main()
{
    struct queue q1;
    q1.front=-1;
    q1.rare=-1;
    int choice;
    for(int i=0;i<Max_size;i++)
    {
        q1.a[i]=-1;
    }

    while(1)
    {
       printf("Enter 1 for display queue,2 for inqueue\n");
       printf("Enter 3 for dequeue element,0 for exit\n");
       printf("Enter choice:");
       scanf("%d",&choice);
       if(choice <=0)
       {
           break;
       }
       else{
         switch(choice)
          {
          case 1:
            {
                Display(q1);
                break;
            }
           case 2:
             {
               int data;
               printf("Enter data to insert data to queue:");
               scanf("%d",&data);
               InqueueData(data,&q1);
               break;
             }
           case 3:
            {
                printf("Deleted element is :%d",Dequeue(&q1));
                break;
            }
           default:
            {
                printf("Something is wrong check choice\n");
            }
          }
      }
   }
    return 0;
}
void InqueueData(int data,struct queue*ptr)
{
     if((ptr->rare==Max_size-1 && ptr->front==0 )|| (ptr->rare+1==ptr->front))
     {
         printf("Queue overflow\n");
     }
     else
     {
        if(ptr->front==-1)
        {
            ptr->front=0;
            ptr->rare=0;
            ptr->a[ptr->rare]=data;
        }
        else
        {
            if(ptr->rare==Max_size-1)
            {
               ptr->rare=0;
               ptr->a[ptr->rare]=data;
            }
            else{
             ptr->rare++;
             ptr->a[ptr->rare]=data;
            }
        }
     }

}
void Display(struct queue ptr)
{
    if(ptr.front==-1 && ptr.rare==-1)
    {
        printf("Queue is empty\n");

    }
    else
    {
        if(ptr.rare > ptr.front)
        {
            for(int i=ptr.front;i<=Max_size-1;i++)
            {
                if(ptr.a[i]==-1)
                {
                    continue;
                }
                else{
                    printf("%d ",ptr.a[i]);
                }

            }
        }
        else
        {
            for(int  i=0;i<=ptr.front;i++)
            {
                if(ptr.a[i]==-1)
                {
                    continue;
                }
                else
                {
                    printf("%d ",ptr.a[i]);
                }

            }
        }
    }

}
int Dequeue(struct queue *ptr)
{
    int data;
     if(ptr->front==-1 && ptr->rare==-1)
     {
         printf("Queue is empty\n");
     }
     else
     {
         if(ptr->front == ptr->rare)
         {
             data=ptr->a[ptr->front];
             ptr->a[ptr->front]=-1;
             ptr->front=-1;
             ptr->rare=-1;
         }
         else
         {
             if(ptr->front==Max_size-1){
                 data=ptr->a[ptr->front];
                 ptr->front=0;
                 ptr->front++;
             }
             else{
               data=ptr->a[ptr->front];
              ++ptr->front;
             }
         }
     }
     return data;
}

