#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"queue-adt.c"
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
   
   
   struct queue *q;
   q=createqueue();
   
   enqueue(q,root);
   
      while( !queueempty(q) )
      {
       
        struct tree *r=(tree*)dequeue(q);
        printf("%d ",r->d);
        if(r->left!=NULL)
        enqueue(q,r->left);
        if(r->right!=NULL)
        enqueue(q,r->right);
      }
       

   
   
   
    getch();
}
    
    
    
    
