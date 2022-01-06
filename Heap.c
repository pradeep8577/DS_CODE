#include <stdio.h>
#include <stdlib.h>
#define Max_size 10
void Inserting(int arr[],int *last_position,int max_size,int data);
void Deleting(int arr[],int *last_position);
void Display(int arr[],int *last_position);
void swap(int arr[],int data1,int data2);
int main()
{
    int a[Max_size];
    int Last_position=-1,choice;
    while(1)
    {
        printf("1]Display heap\n");
        printf("2]Insert data\n");
        printf("3]Delete\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice<=0)
        {
            break;
        }
        else
        {
            switch(choice)
            {
            case 1:
                {
                  Display(a,&Last_position);
                  break;
                }
            case 2:
                {
                    int data;
                    printf("Enter data to insert:");
                    scanf("%d",&data);
                    Inserting(a,&Last_position,Max_size,data);
                    break;
                }
            case 3:
                {
                    Deleting(a,&Last_position);
                    break;
                }
            default:
                {
                    printf("\nCheck choice\n");
                }
            }
        }
    }


    return 0;
}
void swap(int arr[],int data1,int data2)
{
    int tem;
    tem=arr[data1];
    arr[data1]=arr[data2];
    arr[data2]=tem;
}
void Inserting(int arr[],int *last_position,int max_size,int data)
{

      int tem,parent;
      *(last_position)=*(last_position)+1;
      arr[*(last_position)]=data;
      int i=*(last_position);

      while(i>=0)
      {
          parent=(i-1)/2;
         if(arr[parent]<arr[*(last_position)])
         {
             printf("Value of parent:%d\n",parent);
             tem=arr[*(last_position)];
             arr[*(last_position)]=arr[parent];
             arr[parent]=tem;
             i=parent;
         }
         else
         {
             return;
         }

      }
  }

void Display(int arr[],int *last_position)
{
    if(*(last_position)==-1)
    {
        printf("Heap is empty\n");
    }
    else
    {
        for(int i=0;i<=*(last_position);i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
void Deleting(int arr[],int *last_position)
{
    int tem1,tem2,tem3;
    if(*(last_position)==-1)
    {
        printf("Heap is empty\n");
    }
    else
    {
         tem1=arr[0];
         arr[0]=arr[*(last_position)];
         arr[*(last_position)]=tem1;

         printf("\n%d element is deleted\n",arr[*(last_position)]);
         *(last_position)=*(last_position)-1;
        int i=0,leftch,rightch,parent;
        while(i<=*(last_position))
        {
            parent=i;
            leftch=(2*i)+1;
            rightch=(2*i)+2;
            if(arr[leftch]>arr[rightch])
            {
                if(arr[leftch]>arr[parent])
                {
                    tem2=arr[leftch];
                    arr[leftch]=arr[parent];
                    arr[parent]=tem2;
                }
                i=leftch;
            }
            else
            {
                if(arr[rightch]>arr[parent])
                {
                    tem3=arr[rightch];2
                    arr[rightch]=arr[parent];
                    arr[parent]=tem3;
                }
                i=rightch;
            }
        }
    }
}
