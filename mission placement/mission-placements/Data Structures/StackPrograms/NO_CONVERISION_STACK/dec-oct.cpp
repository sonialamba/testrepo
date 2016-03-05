#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"intstackadt.cpp"


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
    s=createstack();
    
    int n=96; // no to be converted to octal
    
    while( n )
    {
           int q=n/8;              
           int r=n%8;            
           push(s,r);          
           n=q;
    }
    disp(s);
    getch();
}
