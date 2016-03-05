/* goal path seeking problem */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"intstackadt.cpp"

void disp(struct stack *s)
{
     struct node *temp=s->top;
     while( temp !=NULL)
     {
            printf("%d ",temp->d);
            temp=temp->next;
     }
}

int main()
{
    struct stack *s;
    s=createstack();
    
    int p[6][6]= {
               {0,1,0,0,0,0},
               {0,0,1,1,0,1},
               {0,0,0,0,0,0},
               {0,0,0,0,1,0},
               {0,0,0,0,0,0},
               {0,0,0,0,0,0},
               };
    
    int v[6]={0};
    int goal=2;
    int n=6;
    push(s,0);
    while( !emptystack(s))
    {
           int end=n-1;
           int curr=stacktop(s);
           v[curr]=1;
             if( curr==goal)
           break;
          while( end!=curr )
           {
                      
                  if( p[curr][end]==1)
                             push(s,end);
                      
                  end--;
       }
       while( v[stacktop(s)]==1)
         pop(s);                     
    }
    
    printf(" The path to reach the goal is ");
    
    while( !emptystack(s) )
        printf("%d ",pop(s));
 
    getch();
}
