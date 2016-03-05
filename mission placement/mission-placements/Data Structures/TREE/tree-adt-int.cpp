#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
       struct node *left;
       struct node *right;
       int d;
};
struct tree
{
       struct node *root;
       int c;
};


tree *create()
{
     struct tree *t=(tree*)malloc(sizeof(tree));
     t->root->left=NULL;
     t->root->right=NULL;
     t->c=0;
}

void addnode(struct node *r,struct node *n)
{
         if( r==NULL)
             r=n;
         else
         {
         if( r->d > n->d )
             addnode(r->left,n);
         else
             addnode(r->right,n);
         }
}


void insert(struct tree *t,int d)
{
         struct node *n=(node*)malloc(sizeof(node));
         n->d=d;
         n->left=NULL;
         n->right=NULL;  
         if ( t->root=NULL)
            t->root=n;
         else
            addnode(t->root,n);
            
         (t->c)++;
}
 

void inorder(struct tree *t)
{
     if(t->root==NULL)
     return;
     else
     {
         inorder(t->root->left);
         printf("%d " ,t->root->d);
         inorder(t->root->right);
     }
}
      
         

int main()
{
    struct tree *t;
    t=create();
    addnode(t,10);
    addnode(t,20);
    addnode(t,5);
    inorder(t);
       
    getch();
}
