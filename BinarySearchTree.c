//write a program for a binary tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **root, int data)
{
    if (*root == NULL)
    {
        *root = (struct node *)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (data < (*root)->data)
    {
        insert(&(*root)->left, data);
    }
    else
    {
        insert(&(*root)->right, data);
    }
}

void display(struct node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void main()
{
     struct node *root = NULL;
     int choice, data;
     while (1)
     {
         printf("\n1.Insert\n2.Display\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
         switch (choice)
         {
         case 1:
             printf("Enter the data: ");
             scanf("%d", &data);
             insert(&root, data);
             break;
         case 2:
             printf("\nThe tree is: ");
             display(root);
             break;
         case 3:
             printf("\nInorder traversal: ");
             inorder(root);
             break;
         case 4:
             printf("\nPreorder traversal: ");
             preorder(root);
             break;
         case 5:
             printf("\nPostorder traversal: ");
             postorder(root);
             break;
         case 6:
             exit(0);
         default:
             printf("Wrong choice\n");
         }
     }
    
}
 