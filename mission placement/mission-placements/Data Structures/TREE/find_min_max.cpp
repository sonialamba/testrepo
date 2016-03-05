#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct tree
{
       int d;
       struct tree *left;
       struct tree *right;
};

void insert(struct tree **root,int d)
{
     if( (*root)==NULL)
     {
          struct tree *n=(tree*)malloc(sizeof(tree));
          n->d=d;
          n->left=NULL;
          n->right=NULL;
         (*root)=n;
     }
     else
     {
         if( (*root)->d > d)
          insert( &( (*root)->left ) ,d);
         else
           insert( &( (*root)->right ) ,d);
     }   
}


int del(struct tree *root,struct tree *parent)
{
     if ( (root)->left == NULL && (root)->right==NULL)
     {
         if(parent->left==(root))
         parent->left=NULL;
         else
         parent->right=NULL;
         free(root);
         return 1;
     }
     else
     {
         if( root->left!=NULL)
         {
             parent=root;
             return( del( root,parent) );
         }
     
     }
}
int search(struct tree *root,int k)
{
    if(root==NULL)
    return -1;
    if( root->d== k)
        return k;
    else
    {
        if( root->d > k )
        return( search( root->left,k) );
        else
        return (search( root->right,k) );
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

int minnode(struct tree *root)
{
    if( root!=NULL )
    {
    if( root->left==NULL)
        return root->d;
    else
        return ( minnode( root->left ) ) ;   
    }
}


int maxnode(struct tree *root)
{
    if( root!=NULL )
    {
    if( root->right==NULL)
        return root->d;
    else
        return ( maxnode( root->right ) ) ;   
    }
}

int main()
{
    struct tree *root=NULL;

    insert(&root,10);
    insert(&root,5);
    insert(&root,4);
    insert(&root,15);
    insert(&root,20);
    
    struct tree *parent=NULL;
    del(root,parent);
    
    getch();
}
