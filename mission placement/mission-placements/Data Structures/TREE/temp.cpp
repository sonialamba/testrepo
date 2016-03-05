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
   
   struct tree *c=root;
   while( !stackempty(s) || c!=NULL)
   {
          while(c!=NULL)
          {
             printf("%d ", c->d);
             push(s,c);
             c=c->left;
          }
          struct tree *r=(tree*)pop(s);
          if(r->right==NULL)
          {
                            struct tree *x=(tree*)stacktop(s);
                            if(x->left==r)
                            {
                                 x->left=NULL;
                             else
                            x->right=NULL;
                             free(c);
                          
                            
          c=r->right;
   }
   

   
   
   
    getch();
}
    
    
    
    
