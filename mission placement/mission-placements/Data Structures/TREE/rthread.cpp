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
       int rightthread;
       int d;
};

void insert(struct tree **root,int d)
{

        struct tree *n=(tree*)malloc(sizeof(tree));
        n->d=d;
     if(*root==NULL)
     {
                    n->left=NULL;
                    n->right=NULL;
                    n->rightthread=false;
                    *root=n;
                    
     }
     else
     {
        struct tree *p=*root;
        while(1)
        {
             if( p->d > d )
             {
                 if( p->left!=NULL)
                     p=p->left;
                 else
                 {  
                     
                 
                     p->left=n;
                     n->left=NULL;
                     n->right=p;
                     n->rightthread=true;
                     
                     return;
                 }
             }
             else
             {
                 if(p->rightthread==false && p->right!=NULL )
                    p=p->right;
                 else
                 {
                    n->right=p->right;
                    if(n->right!=NULL)
                      n->rightthread=true;                     
                    n->left=NULL;      
                    p->right=n;
                    p->rightthread=false;
                    
                    return;
                 }

             }
        }
     }    
}


void inorder(struct tree *root)
{
     struct tree *p=root;
     while(p!=NULL)
     {
        while(p->left!=NULL)
        p=p->left;
      
        printf("%d ",p->d);
     
      //  getch();
        while (p->rightthread==true)
        {
            p=p->right;
            printf("%d ",p->d);
        } 
        p=p->right;
     
     }
}



void preorder(struct tree *root)
{
     struct tree *p=root;
     while(p!=NULL)
     {
         while(p->left!=NULL)  
         {
             printf("%d ",p->d);                      
             p=p->left; 
         } 
     printf("%d ",p->d);                      
        while (p->rightthread==true)
        {
            p=p->right;
        } 
        p=p->right;
     
     }
}


void postorder(struct tree *root)
{
     struct tree *p=root;
     while(p!=NULL)
     {
         while(p->left!=NULL)  
         {
             p=p->left; 
         }
         
         if( p->rightthread==false)
             p=p->right;
         else
             printf(" %d ", p->d);
          
     }
}

int main()
{
    
    struct tree *root=NULL;
    
    insert(&root,10);
   
   
    insert(&root,5);
 
    
    insert(&root,20);
   
    insert(&root,25);
   
   insert(&root,19);
   
    insert(&root,4);
   
    insert(&root,6);

    insert(&root,3);

    insert(&root,2);

    insert(&root,8);

    insert(&root,9);

   
    postorder(root);
   
    getch();
}
    
    
    
    
