#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  int porductID;
  float ProductPrice;
  char productName[10];
  float productGST;
  int NumItems;
  struct node *next;
};
typedef struct node Node;
void DisplayBill(Node *ptr);
void ListOfProduct(Node *ptr);
void InsertProductToBillList(Node **ptr,float PR,int PID,char PName[],float GST,int NumItems);
void DeleteElementFromeList(Node **ptr,int productId);
int NumberOfNodes(Node *ptr);
int main()
{
   Node *head=NULL;
   int  choice;
   while(1)
  {
     printf("Enter 1 for to print total bill,2 Insert product to list\n");
     printf("Enter 3 Display list of items,4 for delete element frome list\n");
     printf("Enter 0 to stop\n");
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
            DisplayBill(head);
            break;
          }
          case 2:
          {
             float PR,GST;
             int PID,NumItems;
             char PName[10];
             printf("Enter product id:");
             scanf("%d",&PID);
             printf("Enter product price:");
             scanf("%f",&PR);
             printf("Enter product name:");
             scanf("%s",PName);
             printf("Enter product GST:");
             scanf("%f",&GST);
             printf("Enter product number of items:");
             scanf("%d",&NumItems);
             InsertProductToBillList(&head,PR,PID,PName,GST,NumItems);
             break;
          }
          case 3:
          {

            ListOfProduct(head);
            break;
          }
          case 4:
          {
            int position;
            printf("Enter product id to delete product from list:");
            scanf("%d",&position);
            DeleteElementFromeList(&head,position);
            break;
          }
          default:
          {
             printf("Something is wrong\n");
          }
        }
     }
  }
  return 0;
}
int NumberOfNodes(Node *ptr)
{
    int count=0;
   if(ptr==NULL)
   {
     return 0;
   }
   else
   {
     while(ptr!=NULL)
     {
       count++;
       ptr=ptr->next;
     }
   }
   return count;
}
void InsertProductToBillList(Node **ptr,float PR,int PID,char PName[],float GST,int NumItems)
{
  Node *p=*ptr;
  Node *n=(Node*)malloc(sizeof(Node));
  n->porductID=PID;
  n->ProductPrice=PR;
  strcpy(n->productName,PName);
  n->productGST=GST;
  n->NumItems=NumItems;
  n->next=NULL;
  if(*ptr==NULL)
  {
    *ptr=n;
  }
  else
  {
    while(p->next!=NULL)
    {
      p=p->next;
    }
    p->next=n;
  }
}
void DisplayBill(Node *ptr)
{
  int NumberOfProduct,count=0;
  float TotalBill=0.0,FinalBill=0.0;

  if(ptr==NULL)
  {
    printf("\nThere is no element in product list\n");
    printf("\nTotal bill is:%d\n",0);
  }
  else
  {
    while(ptr!=NULL)
    {
        printf("\n");
        TotalBill=(ptr->ProductPrice*ptr->NumItems+ptr->productGST*ptr->NumItems);
        FinalBill+=TotalBill;
         printf("Product number:%d\n",count+1);
         printf("Product ID:%d\n",ptr->porductID);
         printf("Product name is:%s\n",ptr->productName);
         printf("Product price is:%.2f\n",ptr->ProductPrice);
         printf("product GST per item:%d\n",ptr->NumItems);
         printf("Number of product taken:%d\n",ptr->NumItems);
         printf("Total bill of product %d is:%.3f\n",count+1,TotalBill);
         ptr=ptr->next;
         printf("\n");
     }
     printf("\nTotal Bill of item list is :%.3f\n",FinalBill);
     printf("\n");
  }
}
void ListOfProduct(Node *ptr)
{
   int count=0;
   if(ptr==NULL)
   {
     printf("Product list is empty\n");
   }
   else
   {
     printf("List of elements that you added into list:\n");
     while(ptr!=NULL)
     {
       printf("Product number:%d\n",count+1);
       printf("Product ID:%d\n",ptr->porductID);
       printf("Product name is:%s\n",ptr->productName);
       printf("Product price is:%.3f\n",ptr->ProductPrice);
       printf("Product GST is:%.3f\n",ptr->productGST);
       printf("Number of product taken:%d\n",ptr->NumItems);
       ptr=ptr->next;
       ++count;
       printf("\n");
     }
   }
   printf("\n");
}
void DeleteElementFromeList(Node **ptr,int productId)
{

  Node *q;
  Node *p=*ptr;

  if(*ptr==NULL)
  {
    printf("Product list is empty\n");
  }
  else if(p->porductID==productId)
  {
    *ptr=p->next;
    free(p);
  }
  else
  {
   while(p!=NULL)
   {
       if(p->porductID==productId)
       {
           printf("Deleted node in list is :%s\n",p->productName);
           q->next=p->next;
           free(p);
           break;
       }
       else
       {
           q=p;
           p=p->next;

       }
   }
   if(p==NULL)
   {
       printf("\nEnter product ID is not match with any of list of products\n");
   }
  }
}
