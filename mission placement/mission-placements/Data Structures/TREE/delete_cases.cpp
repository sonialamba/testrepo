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


tree* search(struct tree *root,struct tree **parent,int k)
{
    if(root==NULL)
    return NULL;
    if( root->d== k)
        return root;
    else
    {
        *parent=root;
        if( root->d > k )
        return( search( root->left,parent,k) );
        else
        return (search( root->right,parent,k) );
    }
}    
void inorder(struct tree *root)
{
     if(root!=NULL)
     {
         inorder(root->left);
         printf("%d ",root->d);
         inorder(root->right);
     }
}


tree* inordersucc(struct tree *x,struct tree **parent)
{
      if( x->left==NULL)
          return x;
      else
      {
          *parent=x;
          return inordersucc( x->left,parent );
      }
}

int deletenode(struct tree **root,int k)
{
    struct tree *parent=NULL;
    struct tree *x=search(*root,&parent,k);
    
    if( x!=NULL )                                           // NODE FOUND
    {
       
            if ( x->left==NULL && x->right==NULL)           //pure leaf node case
            {
                 if( parent->left == x)
                 parent->left=NULL;
                 else
                 parent->right=NULL;
            }
            else  if( x->left!=NULL && x->right==NULL)        // left NOT NULL
            {
                    if( parent->left == x)
                        parent->left=x->left;
                    else
                        parent->right=x->left;
            }
            else if( x->right!=NULL && x->left==NULL)       // RIGHT NOT NULL
            {
                    if(parent->left == x)
                        parent->left=x->right;
                    else
                        parent->right=x->right;
                      
            }
            else
            {
                  parent=x;
                  struct tree *is=inordersucc( x->right, &parent );
                  int t=x->d;
                  x->d = is->d;
                  is->d=t;
                  if(parent!=x)
                    parent->left=NULL;
                  else
                    parent->right=NULL;
                  x=is;
            
            }
        int temp=x->d;
        free(x);
        return temp;
    }
    
    return -1;                                            // node not found
}

int main()
{
    struct tree *root=NULL;

    insert(&root,10);
    insert(&root,5);
    insert(&root,4);
    insert(&root,15);
    insert(&root,14);
    insert(&root,20);
    insert(&root,19);
    insert(&root,21);
     
    printf("\n deleted-%d ",deletenode(&root,20));
    
    inorder(root);    
    getch();
}
