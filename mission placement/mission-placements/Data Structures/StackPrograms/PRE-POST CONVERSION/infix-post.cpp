#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include"charstackadt.cpp"
#define operand 1
#define operator 0

int chkoperand(char ch)
{
    if( (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') )
               return 1;
    else
               return 0;
}


int chkpriority(char ch)
{   
    if(ch=='/' || ch=='*' )
            return 3;
    else if(ch=='+' || ch=='-' )
            return 2;
    else if( ch == '^' )
         return 4;
    else
            return 1;
    
}


int main()
{
    struct stack *s;
    s=createstack();
  
    char in[]="(a+b)*(c*d-e)*f/g";
    char post[40];
    int i=0,c=0;
    
    while(in[i]!='\0')
    {
       char ch=in[i];
       int op=chkoperand(ch);
       if(op==operand)
       post[c++]=in[i];
       else if(op==operator)
       {
            if(stackempty(s) || ch=='(' )
            push(s,ch);
            else if(ch==')' )
            {
               while( stacktop(s)!='(')
               post[c++]=pop(s);
               pop(s);
            
            }
            else
            {
                while( chkpriority(ch)<= chkpriority( stacktop(s) ) )
                {
                       post[c++]=pop(s);
                }
                push(s,ch);
            }
       }
       i=i+1;
    }
    while( !stackempty(s) )
          post[c++]=pop(s);
    post[c]='\0';      
          printf("%s",post);
    getch();
}
