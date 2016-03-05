#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
       struct tree *left;
       struct tree *right;
       int d;
};

tree* createtree()
{
  
                struct tree *n=(tree*)malloc(sizeof(tree));
                n=NULL;
                return n;
}

void insert(struct tree *root,int k)
{
 if(root==NULL)
 {
 printf("k");
   struct tree *n=(tree*)malloc(sizeof(tree));
                    n->left=NULL;
                    n->right=NULL;
                    n->d=k;
    root=n;
 }
 else
 {
     if( k > root->d )
      insert(root->right,k);   
     else
      insert(root->left,k);   
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
int main()
{
    
 struct tree *root=createtree();
 if(root==NULL)
 {
    printf("%d",1);
}
 
 insert(root,10);
 insert(root,20);
 insert(root,30);
 inorder(root);
 //printf("%d",root->left->d);
 getch();
}
