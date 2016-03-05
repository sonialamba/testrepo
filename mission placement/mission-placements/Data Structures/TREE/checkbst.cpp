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

int getheight(struct tree *t)
{
    if ( t ==NULL )
       return 0;
    else
    {
        int left=getheight(t->left);
        int right=getheight(t->right);
        
        if ( left > right )
           return left+1;
        else
            return right+1;
    }       
}

int getmin( struct tree *t)
{   
    if( t == NULL )
       return 32767;
       
    if( t->left== NULL && t->right==NULL )
        return t->d ;
    else
    {
        int left=getmin(t->left);
        int right=getmin(t->right);
        int min;
        if( left < right )
            min=left;
        else
            min=right;
        
        if( t->d < min )
            return t->d;
        else
            return min;
        
    }
}

int getmax( struct tree *t)
{   
    if( t == NULL )
       return -1;
       
    if( t->left== NULL && t->right==NULL )
        return t->d ;
    else
    {
        int left=getmax(t->left);
        int right=getmax(t->right);
        int max;
        if( left > right )
            max=left;
        else
            max=right;
        
        if( t->d > max )
            return t->d;
        else
            return max;
        
    }
}

int isbst(struct tree *t)
{
    if( t==NULL )
        return 1;
    else if( t->left!=NULL && t->d < getmax(t->left) )
        return 0;
    else if( t->right!=NULL && t->d > getmin(t->right) )
        return 0;
    else
    return ( isbst( t->left ) && isbst ( t->right ) ) ;
    
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
       
    
    
    printf("\n %d", isbst(t) );    

            
    getch();
}
