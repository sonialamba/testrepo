#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"intstackadt.cpp"

/* the file imports stack abstract data type  and performs logic */
 
 
 
void disp(struct stack *s)
{
     struct node *t=s->top;
     while(t!=NULL)
     {
        printf("%d",t->d);
        t=t->next;
     }
}

int main()
{
    struct stack *s;
    s=createstack();                // creates stack
    
    
    int q,r;
    int div=6;                    // no to be converted to decimal
    
    while(div)
    {
               q=div/2;
               r=div % 2;
               push(s,r);
               div=q;
    }
    
    
   disp(s);    
   getch();
}
