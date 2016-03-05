#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"generic-stack.c"
#define placed 1
#define start 0
#define end 3
#define rr 1
#define rc 0
#define collision 1

struct pos
{
       int r;
       int c;
};


void disp(struct stack *s)
{
     struct node *t=s->top;
     printf("\n STACK PRINT \n");
     while(t!=NULL)
     {
        struct pos *p=(pos*)(t->data);
        printf("row-%d col-%d \n",p->r,p->c);
        t=t->next;
     }
}

int checkCollision(int board[][4],int row,int col)
{


    for(int i=row-1;i>=start;i--)
    {
      if( board[i][col]==placed )
          return 1;
    }


    int c=col;
    for(int i=row-1;i>=start;i--)
    {
      c=c-1;
      if( board[i][c]==placed )
       return 1;
      if( c==start)
      break;
    }

    c=col;
    for(int i=row-1;i>=start;i--)
    {
      c=c+1;
      if( board[i][col]==placed )
          return 1;
      if( col==end)
      break;
    }
return 0;
}

int main()
{
    struct stack *s;
    s=createstack();
    
    int board[4][4]= {0};
    int qplaced=1,backtrack=0;
    
    struct pos *p=(pos*)malloc(sizeof(pos));
    p->r=0;
    p->c=0;
    
    push(s,p);
    board[0][0]=1;
    int curr,c;
    while( qplaced!=4 )
    {
           int flag=0;
           if( backtrack )
           {
                struct pos *p=(pos*)pop(s);
                curr=p->r;
                c=p->c;
               board[curr][c]=0;
               c=c+1;
              free(p);
           }
           else
           {
           
             struct pos *p=(pos*)stacktop(s);
                curr=(p->r)+1;
             
              c=0; 
           }
           for( ;c<=end;c++)
           {
           
                if(  checkCollision(board,curr,c)!=collision )
                {
                    board[curr][c]=1;
                    struct pos *p=(pos*)malloc(sizeof(pos));
                    p->r=curr;
                    p->c=c;                    
                    push(s,p);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            backtrack=1;
            else
            backtrack=0;
            qplaced=stackcount(s);
   }
   
   disp(s);
   getch();
}
