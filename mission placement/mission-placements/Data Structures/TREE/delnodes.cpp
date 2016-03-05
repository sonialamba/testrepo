#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tree
{
        struct tree *left;
        struct tree *right;
        int d;
};

void insert(struct tree **t,int d)
{
    if( *t == NULL )
    {
        struct tree *n=(tree*)malloc(sizeof(tree));
        n->d=d;
        n->left=NULL;
        n->right=NULL;
        *t=n;
    }
    else
    {
        if(  (*t)->d > d )
             insert(  & ( (*t)->left ) , d );
        else
             insert( & ( (*t)->right ) , d );
    }
}

tree *freetree(struct tree *t)
{
     if( t!=NULL )
     {
         t->left=(freetree(t->left) );
         
         t->right=(freetree(t->right) );
         
         free(t);
 
     }

     return NULL;
}
    
void inorder(struct tree *t)
{
     if( t != NULL )
     {
         inorder( t->left );
         printf("%d ",t->d);
         inorder ( t->right);
     }
}

int main()
{
    
    struct tree *t=NULL;
    
    insert(&t,50);
    insert(&t,40);
    insert(&t,100);
    insert(&t,120);
    insert(&t,10);
    insert(&t,30);
    
    inorder(t);
    
    t=freetree(t);   
    inorder(t);
    
    
 
    getch();
}
