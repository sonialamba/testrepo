#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"queue-adt.c"
#define true 1
#define false 0
struct tree
{
       struct tree *left;
       struct tree *right;
       int leftthread;
       int rightthread;
       int d;
};

void insert(struct tree **root,int d)
{

        struct tree *n=(tree*)malloc(sizeof(tree));
        n->left=NULL;
        n->right=NULL;
        n->d=d;
    if(*root==NULL)
     {
     
                    n->left=n;
                    n->right=n;
                    n->leftthread=true;
                    n->rightthread=true;
                    *root=n;
                    
     }
     else
     {
         struct tree *p=*root;
        while(1)
        {
             if( p->d > d )
             {
                 if( p->leftthread==false )
                     p=p->left;
                 else
                 {  
                     
                     n->left=p->left;
                     n->leftthread=true;
                 
                     p->left=n;
                     p->leftthread=false;
                   
                     n->right=p;
                     n->rightthread=true;
                     
                     return;
                 }
             }
             else
             {
                 if(p->rightthread!=true )
                    p=p->right;
                 else
                 {
                    n->right=p->right;
                    n->rightthread=true;
                    
                    p->right=n;
                    p->rightthread=false;
                    
                    n->left=p;
                    n->leftthread=true;
                    
                    return;
                 }
             }
        }
     }    
}


void inorder(struct tree *root)
{
     struct tree *p=root;
     do
     {
        while(p->leftthread==false)
        p=p->left;
        printf("%d",p->d);
        while(p->rightthread==true)
        {
           p=p->right;
           if(p==root)
           break;
           printf("%d",p->d);
        }
        p=p->right;
     }while(p!=root);
}


int main()
{
    
    struct tree *root=NULL;
    
    insert(&root,10);
   
    insert(&root,5);
  
    insert(&root,20);
   
  
   
    inorder(root);
   
    getch();
}
    
    
    
    
