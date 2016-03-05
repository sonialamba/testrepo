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


int maxheight(struct tree *root)
{
    if(root==NULL)
     return 0;
    else
    {
       int l=maxheight(root->left);
       int r=maxheight(root->right);
       
       if(l>r)
       return l+1;
       else 
       return r+1;
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
   
   printf("%d",maxheight(root));
   
   getch();
}
   
   
   
    
    
    
    
