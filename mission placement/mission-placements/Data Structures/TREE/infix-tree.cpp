// program to create expression tree 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"generic-stack.c"
struct tree
{
       struct tree *left;
       struct tree *right;
       char d;
};

void insert(struct tree **root,char d)
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

int isoperand(char c)
{
    if( c=='+' || c=='-' || c=='/' || c=='*' )
    return 0;
    else
    return 1;
}


int isparent(struct tree *root)
{
    if( root->left!=NULL || root->right!=NULL)
        return 1;
        else
        return 0;
}

void inorder(struct tree *root)
{
     if(root!=NULL)
     {
        if( isparent(root) )
        {
         printf("(");
         inorder(root->left);
         printf("%c ",root->d);
         inorder(root->right);
         printf(")");
        }
        else
        {
         printf("%c ",root->d);
        }   
        
     }
} 





void disp(struct stack *s)
{
     struct node *t=s->top;
     printf("stack trace");
     while( t!=NULL)
     {
            struct tree *k=(tree*)t->data;
            printf("%c", k->d);
            t=t->next;
     }
       printf("\n");
}            



void preorder(struct tree *root)
{
     if(root==NULL)
     return;
     else
     {
         printf("%c ",root->d);
         preorder(root->left);
         preorder(root->right);
     }
}

void postorder(struct tree *root)
{
     if(root==NULL)
     return;
     else
     {
         postorder(root->left);
         postorder(root->right);
         printf("%c ",root->d);
     }
}


int main()
{
    
    char post[]="abcd+*+";
    int i=0;
    struct stack *s=createstack();
    while( post[i] )
    {
           if( isoperand(post[i]) )
           {
               struct tree *r=(tree*)malloc(sizeof(tree));
               r->d=post[i];
               r->left=NULL;
               r->right=NULL;
               push(s,r);
           }
           else
           {
               struct tree *right1=(tree*)pop(s);
               struct tree *left1=(tree*)pop(s);
               struct tree *root=(tree*)malloc(sizeof(tree));
               root->d=post[i];
               root->left=left1;
               root->right=right1;
               push(s,root);
           }    
           i=i+1;
    }

    struct tree *root=(tree*)pop(s);    
    //preorder(root);
      inorder(root);
    
    getch();
}
    
    
    
    
