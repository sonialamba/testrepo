#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"charstackadt.cpp"
#define digit 1
#define operator 0


int chkoperand(char ch)
{
    if( ch>='0' && ch<='9' || ch>='a' && ch<='z' )
    return 1;
    else
    return 0;
}

int priority(char ch)
{
     if(ch=='/' || ch=='*' )
            return 3;
    else if(ch=='+' || ch=='-' )
            return 2;
    else
            return 1;
}
    
void disp(struct stack *s)
{
     struct node *temp=s->top;
     while(temp!=NULL)
     {
                      printf("%c",temp->d);
                      temp=temp->next;
     }
}
int main()
{
    struct stack *s,*in,*prefix;
    
    in=createstack();
    s=createstack();
    prefix=createstack();
    char infix[]="(a+b)*(c+d/e)-k";   // this is converted to prefix
    int i=0;
    
    while(infix[i]!='\0')
    {
      push(in,infix[i]);
      i++;
    }
    while( !stackempty(in) )
    {
           char ch=pop(in);
           
           int op=chkoperand(ch);
           if(op==digit)
           {
                       push(prefix,ch);
           }
           else if(op==operator)
           {
                if( ch==')' || stackempty(s) )
                push(s,ch);
                else if( ch=='(' )
                {
                     while( stacktop(s) != ')' )
                     push(prefix,pop(s));
                     pop(s);
                }
                else
                {
                    while( priority (ch) <= priority ( stacktop(s) ) )
                    {
                          
                           char c=pop(s);
                           push(prefix,c);
                    }
                    push(s,ch);
                }
           }
    }
    
    while( !stackempty(s) )
    push(prefix,pop(s) );
    
    disp(prefix);
    getch();
}
