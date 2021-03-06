#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
typedef struct node Node;

Node *creatnode(int d)
{
    Node *q=malloc(sizeof(Node));
    q->left=NULL;
    q->data=d;
    q->right=NULL;
    return q;
}

void Insert(Node **root,int Data)
{
    Node *p=*root;
    Node *q;
    if(p==NULL)
    {
        q=creatnode(Data);
        *root=q;
    }
    else
    {
        while(1)
        {
            if(Data<(p->data))
            {
                if((p->left)==NULL)
                {
                    q=creatnode(Data);
                    (p->left)=q;
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
                    q=creatnode(Data);
                    (p->right)=q;
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

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder((root->left));
        printf("%d ",(root->data));
        inorder((root->right));
    }
}

void preorder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ",(root->data));
        preorder((root->left));
        preorder((root->right));
    }
}

void postorder(Node *root)
{
    if(root != NULL)
    {
        postorder((root->left));
        postorder((root->right));
        printf("%d ",(root->data));
    }
}

void Display(Node *root)
{
    int n;
    if(root==NULL)
    {
        printf("Tree is Empty.\n");
    }
    else
    {
        printf("INORDER: ");
        inorder(root);
        printf("\n");
        printf("PREORDER: ");
        preorder(root);
        printf("\n");
        printf("POSTORDER: ");
        postorder(root);
        printf("\n");
    }
}

int Delete(Node **root,int Data1)
{
    Node *curr=*root;
    Node *parent=NULL;
    Node *ptr=*root;
    Node *newcurr;
    Node *p,*r;

    while(curr != NULL && (curr->data)!=Data1)
    {
        if(Data1 < (curr->data))
        {
            parent=curr;
            curr=curr->left;
        }
        else
        {
            parent=curr;
            curr=curr->right;
        }
    }
    if(curr==NULL)
    {
        printf("Given Data is not present in Tree.\n");
        return 1;
    }
    else
    {
        if((curr->left)==NULL && (curr->right)==NULL)
        {
            if(curr->data==ptr->data)
            {
                *root=NULL;
                free(curr);
            }
            else if((parent->left)==NULL)
            {
                (parent->right)=NULL;
				free(curr);
            }
            else
            {
                (parent->left)=NULL;
				free(curr);
            }
            return 0;
        }
        else
        {
            if((curr->left)==NULL || (curr->right)==NULL)
            {
                if(curr->data==ptr->data)
                {
                    if((curr->left)==NULL)
                    {
                        *root=curr->right;
                    }
                    else
                    {
                        *root=curr->left;
                    }
                    free(curr);
                }
                else
                {
                    if((curr->left)==NULL)
                    {           
                        newcurr=(curr->right);
                    }
                    else
                    {
                        newcurr=(curr->left);
                    }
                
                    if((parent->left)==NULL)
                    {
                        (parent->right)=newcurr;
					    free(curr);
                    }
                    else
                    {
                        (parent->left)=newcurr;
					    free(curr);
                    }
                }
                return 0;
            }
            else
            {
                r=p=(curr->right);
                while((p->left)!=NULL)
                {
                    r=p;
                    p=(p->left);
                }
                if((p->right)!=NULL)
                {
                    (r->left)=(p->right);
					(curr->data)=(p->data);
                	free(p);
                }
                else
                {
                    (r->left)=NULL;
					(curr->data)=(p->data);
                	free(p);
                }
                return 0;
            }
        }
    }
}

void main()
{
    Node *root=NULL;
    int ch,Data;
    int r,Data1;
    while(1)
    {
        printf("\nEnter 1:-INSERT  2:-DELETE  3:-DISPLAY  4:-EXIT.\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter data to insert in tree: ");
            scanf("%d",&Data);
            Insert(&root,Data);
            break;

            case 2:
            printf("Enter data which you want to delete from tree: ");
            scanf("%d",&Data1);
            r=Delete(&root,Data1);
            if(r==1)
            {
                printf("Element can not be deleted.\n");
            }
            else
            {
                printf("Data deleted successfully.\n");
            }
            break;

            case 3:
            Display(root);
            break;

            case 4:
            exit(0); 
			break;

			default:
			printf("Entered Invalid Input.\n");
        }
    }
}
