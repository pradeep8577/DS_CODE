#include <stdio.h>
#include <stdlib.h>
struct node
{
  struct node *left;
  int data;
  struct node *right;
};
typedef struct node Node;
Node *CreateNode(int data);
void InsertNode(Node **ptr,int data);
void DisplayInorder(Node *ptr);
void DisplayPreorder(Node *ptr);
void DisplayPostorder(Node *ptr);
void DeleteNode(Node **ptr,int data);
int main()
{
    Node *root=NULL;
    int choice;
    while(1)
    {

        printf("1]Inserting\n");
        printf("2]Display\n");
        printf("3]Delete\n");
        printf("0]Stop\n");
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
                    int  data;
                    printf("Enter data to insert data to tree:");
                    scanf("%d",&data);
                    InsertNode(&root,data);
                    break;
                }
            case 2:
                {
                    if(root==NULL)
                    {
                      printf("Tree is empty\n");
                    }
                   else
                    {
                       printf("Inorder:");
                       DisplayInorder(root);
                       printf("\n");
                       printf("Postrorder:");
                       DisplayPreorder(root);
                       printf("\n");
                       printf("Priorder:");
                       DisplayPostorder(root);
                       printf("\n");
                    }
                    printf("\n");

                    break;
                }
            case 3:
                {
                  int data;
                  printf("Enter data to delete nood:");
                  scanf("%d",&data);
                  DeleteNode(&root,data);
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
Node *CreateNode(int data)
{
    Node *p=(Node *)malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("Error in allocate memorey\n");
        return NULL;
    }
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void InsertNode(Node **ptr,int data)
{

    Node *p=*ptr;
    Node *q=CreateNode(data);
    if(*ptr==NULL)
    {

        *ptr=q;
    }
    else
    {
        while(1){
            if(data<p->data)
            {
              if(p->left==NULL)
              {
                p->left=q;
                break;
              }
             else
             {
                 p=p->left;
             }
           }
          else
          {
             if(p->right==NULL)
             {
                 p->right=q;
                 break;
             }
             else
             {
                 p=p->right;
             }
          }
        }

    }
}
void DisplayInorder(Node *ptr)
{
   Node *p=ptr;
  if(ptr==NULL)
  {

      return;
  }
  else
  {

         DisplayInorder(ptr->left);
         printf("%d ",ptr->data);
         DisplayInorder(ptr->right);
  }
}
void DisplayPreorder(Node *ptr)
{
    if(ptr==NULL)
    {
        return ;
    }
    else{
      printf("%d ",ptr->data);
      DisplayPreorder(ptr->left);
      DisplayPreorder(ptr->right);
    }
}
void DisplayPostorder(Node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        DisplayPostorder(ptr->left);
        DisplayPostorder(ptr->right);
        printf("%d ",ptr->data);

    }
}
void DeleteNode(Node **ptr,int data)
{

  Node *p=*ptr;
  Node *curr=*ptr;
  Node *parent=NULL;
  if(*ptr==NULL)
  {
    printf("Tree is empty\n");
  }
  else if(curr->data==data)
  {
      if(curr->left==NULL && curr->right==NULL)
      {
          *ptr=NULL;
          free(curr);
      }
      else if(curr->left==NULL && curr->data==data)
      {
          parent=curr;
          curr=curr->right;
          if(curr->left==NULL)
          {
              *ptr=curr;
              free(parent);
          }
          else{
          while(1){
          if(curr->left==NULL)
          {
              (*ptr)->data=curr->data;
              parent->left=curr->right;
              free(curr);
              break;
        }
          else
          {
              parent=curr;
              curr=curr->left;
          }
        }
          }
      }
      else if(curr->right==NULL && curr->data==data)
      {
           parent=curr;
           curr=curr->left;
           if(curr->right==NULL)
          {
              *ptr=curr;
              free(parent);
          }
          else{
           while(1)
           {
               if(curr->right==NULL)
               {
                   (*ptr)->data=curr->left;
                   parent->left=curr->left;
                   free(curr);
               }
               else
               {
                   parent=curr;
                   curr=curr->right;
               }
           }
          }

      }
      else if(curr->data==data && curr->left!=NULL && curr->right!=NULL)
      {
          parent=curr;
          curr=curr->right;
          if(curr->left==NULL)
          {
              (*ptr)->data=curr->data;
              parent->right=curr->right;
              free(curr);
          }
          else
          {
              while(1)
              {
                  if(curr->left==NULL)
                  {
                      (*ptr)->data=curr->data;
                       parent->left=curr->left;
                       free(curr);
                       break;
                  }
                  else
                  {
                      parent=curr;
                      curr=curr->left;
                  }
              }
          }
      }
    }
  else
  {
    while(p!=NULL)
    {

       if(p->data==data)
       {
         curr=p;
         break;
       }
       else
       {
        if(data<p->data)
        {
          parent=p;
          p=p->left;
        }
        else
        {
          parent=p;
          p=p->right;
        }
       }
    }
    if(p==NULL)
    {
      printf("Enter element is not present in tree\n");
      printf("\n");
    }
    else
      {
         if(curr->left==NULL || curr->right==NULL)
         {
             if(curr->left==NULL && curr->right!=NULL)
              {
                if(parent->left==curr)
                 {
                   parent->left=curr->right;
                 }
                else
                 {
                    parent->right=curr->right;
                 }

              }
              else
               {
                  if(parent->left==curr)
                 {
                   parent->left=curr->left;
                 }
                else
                 {
                    parent->right=curr->left;
                 }

               }
         }
         else
          {
            Node *q=curr->right;
            Node *r;
            while(q->left!=NULL)
            {
               r=q;
               q=q->left;
            }
            if(q->right==NULL)
            {
               r->left=q->right;
            }
            else
            {
                r->left=q->left;
            }
            curr->data=q->data;
            free(q);
          }
      }

    }



  }


