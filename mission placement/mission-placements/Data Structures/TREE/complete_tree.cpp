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
   insert(&root,30);
    insert(&root,15);
   
   
   struct queue *q;
   q=createqueue();
   
   enqueue(q,root);
   int flag=1;
   
   while( !queueempty(q) )
   {
          struct tree *r=(tree*)dequeue(q);
          if(r->left!=NULL && r->right!=NULL)
          {
           enqueue(q,r->left);
           enqueue(q,r->right);
          }
          else
          {
            flag=0;
            break;
          }
   }
   if(flag)
   printf("complete");
   else
   printf("non-complete");
   
   getch();
}
   
   
   
    
    
    
    
