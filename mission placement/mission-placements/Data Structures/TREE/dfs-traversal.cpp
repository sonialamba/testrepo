#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"C:\Dev-Cpp\STACK\generic-stack.c"
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


void disp(struct stack *s)
{
struct node *t=s->top;
printf("Stack trace-");
 while( t!=NULL)
{
        struct tree *k=(tree*)t->data;
printf("%d ",k->d);
t=t->next;
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
   
   
   struct stack *s;
   s=createstack();
   
   
      struct tree *c;
      c=root;
   do
   {
         while(c!=NULL)
         {
         push(s,c);
         c=c->left;
         }
         struct tree *r=(tree*)pop(s);
         printf("%d ",r->d);
         c=r->right;
         
      }while( !stackempty(s) || c!=NULL);
       

   
   
   
    getch();
}
    
    
    
    
