/* program to evaluate prefix (polish) notation */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"intstackadt.cpp"
#define digit 1
#define operator 0
     
int chkoperand(char ch)
{
    if( ch>=48 && ch<=57  )
    return 1;
    else
    return 0;
}

int evaluate(int a,int b,char ch)
{
 switch(ch)
 {
           case '+' :
                return a+b;
           case '-' :
                return a-b;
           case '*' :
                return a*b;
           case '/' :
                return a/b;
 }     
     
}
    
void disp(struct stack *s)
{
     struct node *temp=s->top;
     while(temp!=NULL)
     {
                      printf("%d ",temp->d);
                      temp=temp->next;
     }
}
int main()
{
    struct stack *s,*in,*prefix;
    in=createstack();
    s=createstack();
    prefix=createstack();
    char pre[]="-*2+345";
    int i=0;
    
    while( pre[i] != '\0' )
    {
           push(prefix,pre[i]);
           i++;
    } 
    
    while( !emptystack(prefix) )
    {
           char ch=pop(prefix);
           int op=chkoperand(ch);
    
           if(op==digit)
               push(s,(ch-48));
           else if(op==operator)
           {
                int op1=pop(s);
                int op2=pop(s);
                push(s,evaluate(op1,op2,ch));
           }
    }
    
    disp(s);
    getch();
}
