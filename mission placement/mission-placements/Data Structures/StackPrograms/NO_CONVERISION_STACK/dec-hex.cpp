#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"intstackadt.cpp"

char convert(int n)
{
     if( n < 10)
     return '0'+n;
     else
     return 'A'+ n - 10 ;
}

int dispnumber(stack *s  )
{
    while(!emptystack(s) )
    {
        char c = (char) pop (s) ;   // stack is in integer so converted to char again
        printf("%c",c );
    }
}

int main()
{
    struct stack *s;
    s=createstack();
    
    int n=30;
    
    while( n )
    {
           int q=n/16;              
           int r=n%16;
           char c=convert(r);            
           push(s,c);          
           n=q;
    }
    
    dispchar(s);    
    getch();
}
