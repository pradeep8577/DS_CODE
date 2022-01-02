#include <stdio.h>
#include <stdlib.h>
struct employee
{
  int ID;
  char name[20];
  float salary;
}e[10];
void Display();
int hashFun(int data);
void InsertByHashing(int data);
void SearchingByHashing(int data);
void DeletingElement(int data);
int main()
{
    for(int i=0;i<10;i++)
    {
      e[i].ID=-1;
    }
    int choice;
    while(1)
    {
       printf("\nEnter 1 for display list,2 for inserting\n");
       printf("Enter 3 for searching element,4 for deleting element in list,0 for stop\n");

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
               Display();
               break;
             }
          case 2:
           {
               int data;
               printf("Enter ID:");
               scanf("%d",&data);
               InsertByHashing(data);
               break;
           }
          case 3:
            {
                int data1;
                printf("Enter data to find in list:");
                scanf("%d",&data1);
                SearchingByHashing(data1);
                break;
            }
          case 4:
            {
                 int data2;
                 printf("Enter data to delete in list:");
                 scanf("%d",&data2);
                 DeletingElement(data2);
                 break;
            }
          default:
           {
             printf("Some thing is wrong\n");
           }
       }
     }
   }


    return 0;
}
void Display()
{
  for(int i=0;i<10;i++)
  {
      if(e[i].ID==-1)
      {
          continue;
      }
      else{
         printf("Id of %d employee is:%d\n",i+1,e[i].ID);
         printf("Name of %d employee is:%s\n",i+1,e[i].name);
         printf("Salary of %d employee is:%f\n",i+1,e[i].salary);
      }
  }
}
int hashFun(int data)
{
   return data%10;
}
void InsertByHashing(int data)
{
  int flage=0;
  int ind=hashFun(data);
  if(e[ind].ID==-1)
  {
     e[ind].ID=data;
     printf("Enter name :");
     scanf("%s",e[ind].name);
     printf("Enter salary:");
     scanf("%f",&e[ind].salary);
  }
  else
  {
    for(int i=ind+1;i<10;i++)
    {
        if(e[i].ID==-1)
        {
          e[i].ID=data;
          printf("Enter name:");
          scanf("%s",e[i].name);
          printf("Enter salary:");
          scanf("%f",&e[i].salary);
          flage=1;
          break;
        }
    }
    if(flage==0)
  {
        for(int i=0;i<ind;i++)
         {
            e[i].ID=data;
            printf("Enter name:");
            scanf("%d",e[i].name);
            printf("Enter salary:");
            scanf("%f",&e[i].salary);
            flage=1;
            break;
         }
    }
       if(flage==0)
        {
           printf("List is full\n");
        }
  }

  return;
}
void SearchingByHashing(int data)
{
    int flage=0;
   int ind=hashFun(data);
    if(e[ind].ID==data)
    {
        printf("Name:%s\n",e[ind].name);
        printf("Salary:%f\n",e[ind].salary);
    }
    else
    {
        for(int i=ind+1;i<10;i++)
        {
            if(e[i].ID==data)
            {
                 printf("Name:%s\n",e[i].name);
                 printf("Salary:%f\n",e[i].salary);
                 flage=1;
                 break;
            }
        }
        if(flage==0)
        {
            for(int i=0;i<ind;i++)
            {
                printf("Name:%d\n",e[i].name);
                printf("Salary:%f\n",e[i].salary);
                flage=1;
                break;
            }
        }
        if(flage==0)
        {
            printf("Enter data is not found in list\n");
        }
    }
}
void DeletingElement(int data)
{
   int flage=0;
   int ind=hashFun(data);
   if(e[ind].ID==data)
   {
       e[ind].ID=-1;
   }
   else
   {
       for(int i=ind+1;i<10;i++)
       {
           if(e[i].ID==data)
           {
               e[i].ID=-1;
               flage=1;
               break;
           }
       }
       if(flage==0)
       {
           for(int i=0;i<ind;i++)
           {
               if(e[i].ID==data)
                {
                   e[i].ID=-1;
                   flage=1;
                   break;
                }

           }
       }
       if(flage==0)
       {
           printf("\nEnter data is not there in list\n");
       }
   }

}
