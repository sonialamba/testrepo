#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"queue-adt.c"
struct tree
{
       struct tree *left;
       struct tree *right;
       int d;
};


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
     if(root!=NULL)
     {
         printf("%d ",root->d);
         preorder(root->left);
         preorder(root->right);
     }
}

int height(struct tree *root)
{
    if(root==NULL)
    return 0;
    else
    {
        int left=height(root->left);
        int right=height(root->right);
        if(left>right)
        return 1+left;
        else
        return 1+right;
    }
}

int checkheight(struct tree *root)
{
    int left=height(root->left);
    int right=height(root->right);
    return (left-right);  
}


void rotateright(struct tree **root)
{
     struct tree *temp=(*root)->left;
     (*root)->left=temp->right;
     temp->right=*root;
     *root=temp;
}


void rotateleft(struct tree **root)
{
     struct tree *temp=(*root)->right;
     (*root)->right=temp->left;
     temp->left=*root;
     *root=temp;
}
     
void bfs(struct tree *root)
{
   struct queue *q;
   q=createqueue();
   
   enqueue(q,root);
   
      while( !queueempty(q) )
      {
       
        struct tree *r=(tree*)dequeue(q);
        printf("%d ",r->d);
        if(r->left!=NULL)
        enqueue(q,r->left);
        if(r->right!=NULL)
        enqueue(q,r->right);
      }
       
}
   

void avlbalance(struct tree **root)
{
    int bf=checkheight(*root);
    if( bf > 1)                                         // left unbalance
    {
        int f=checkheight( (*root)->left );
        if ( f >=1 )
        {
             rotateright(root);                        // left-left case
        }
        else
        {
            rotateleft( &( (*root)->left ) );         // right-left case
            rotateright( root );
        }
    }
    else if( bf < -1 )
    {
        int f=checkheight( (*root)->right );
        if( f <= -1 )
        {
            rotateleft(root);                         // right-right case
        }
        else
        {
           rotateright( &( (*root)->right ) );       //left-right case
           rotateleft( root );
        }
    }
}

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

int main()
{ 
    struct tree *root=NULL;  
    insert(&root,10);
    insert(&root,20);
    insert(&root,15);
     
    avlbalance(&root);
    printf("\n");
   
    bfs(root);  
   
    getch();
}
    
    
    
    
