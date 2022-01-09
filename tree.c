#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* left;
    int data;
    struct node* right;
};
void Insert();
void Display();
void main()
{
    struct node* root=NULL;
    int ch,item;
    while(1){
        printf("Tree implemention\n");
        printf("1.INSERT\n");
        printf("2.DISPLAY\n");
        printf("3.QUIT\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:printf("Enter the item:");
                   scanf("%d",&item);
                   Insert(&root,item);
                   break;
            case 2:Display(root);             
                   break;
            case 3:exit(0);
                  break;
            default:printf("Invalid input\n");
        }
    }
}
struct node *creatnode(int d)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

}
void Insert(struct node **root,int Data)
{
    struct node *p=*root;
    struct node *temp;
    if(p==NULL)
    {
        temp=creatnode(Data);
        *root=temp;
    }
    else
    {
        while(1)
        {
            if(Data<(p->data))
            {
                if((p->left)==NULL)
                {
                    temp=creatnode(Data);
                    (p->left)=temp;
                    break;
                }
                else
                {
                    p=(p->left);
                }
            }
            else
            {
                if((p->right)==NULL)
                {
                    temp=creatnode(Data);
                    (p->right)=temp;
                    break;
                }
                else
                {
                    p=(p->right);
                }
            }
        }
    }
}

void Inorder(struct node* root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
void Preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Postorder(struct node* root)
{
if(root!=NULL)
{
Postorder(root->left);
Postorder(root->right);
printf("%d ",root->data);
}
}
void Display(struct node* root)
{  
if(root==NULL)
{
    printf("Tree is empty\n");
} 
else
{
 printf("Inoder is:");
 Inorder(root);
 printf("\n");
 printf("Preoder is:");
 Preorder(root);
 printf("\n");
 printf("postorder is:");
 Postorder(root);
 printf("\n");
}
}

