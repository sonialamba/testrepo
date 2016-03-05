#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
       struct tree *left;
       struct tree *right;
       int d;
};

void insert(struct tree **root,int d)
{
     if(*root==NULL)
     {
                    struct tree *n=(tree*)malloc(sizeof(tree));
                    n->left=NULL;
                    n->right=NULL;
                    n->d=d;
                    *root=n;
     }
     else
     {
         if( (*root)->d > d)
             insert( &( (*root)->left ) , d);
         else
             insert( &( (*root)->right ) , d);
     }
}

int isparent(struct tree *root)
{
    if( root->left!=NULL || root->right!=NULL)
        return 1;
    else
        return 0;
}


void putbrace(struct tree *root)
{
     if(root!=NULL)
     {
       printf("%d",root->d);
       if( isparent(root) )
       {
           printf("(");
           putbrace(root->left);
           putbrace(root->right);
           printf(")");
       }
     }
}
           


void inorder(struct tree *root)
{
     if(root==NULL)
     return;
     else
     {
         inorder(root->left);
         printf("%d ",root->d);
         inorder(root->right);
     }
}

void preorder(struct tree *root)
{
     if(root==NULL)
     return;
     else
     {
         printf("%d ",root->d);
         inorder(root->left);
         inorder(root->right);
     }
}

void postorder(struct tree *root)
{
     if(root==NULL)
     return;
     else
     {
         inorder(root->left);
         inorder(root->right);
         printf("%d ",root->d);
     }
}

int main()
{
    
    struct tree *root=NULL;
    
    insert(&root,10);
    insert(&root,20);
    insert(&root,5);
    insert(&root,4);
    insert(&root,6);
   
    putbrace(root);
    getch();
}
    
    
    
    
