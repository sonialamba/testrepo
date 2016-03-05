#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"C:\Dev-Cpp\STACK\generic-stack.c"
struct tree
{
       struct tree *left;
       struct tree *right;
       int vl;
       int vr;
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
   
   
   struct save
   {
          struct tree *r;
          int vl;
          int vr;
   };
   
   struct save *c;
   c->r=root;
   c->vl=0;
   c->vr=0;
   push(s,c);
   
   while( !stackempty(s) )
   {
          struct save *c=(save*)stacktop(s);
          struct tree *n=(tree*)c->r;
          if( n->left!=NULL && !c->vl )
          {
              c->vl=1;
              struct save *c=(save*)malloc(sizeof(save));
              c->r=n->left;
              push(s,c);
              continue;
          }
          
          if( n->right!=NULL && !c->vr )
          {
              c->vr=1;
             struct save *c=(save*)malloc(sizeof(save));
              c->r=n->right;
              continue;
          }
          
              printf("%d ",n->d);
              pop(s);
   }
   

   
   
   
    getch();
}
    
    
    
    
