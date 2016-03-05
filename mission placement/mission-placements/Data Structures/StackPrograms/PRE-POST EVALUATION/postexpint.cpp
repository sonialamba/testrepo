#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"intstackadt.cpp" // imports integer stack abstract data type
#define digit 1
#define operator 0

char evaluate(int a , int b, char ch)
{
     switch(ch)
     {
     case '+' :
          return (a+b);
     case '-' :
          return (b-a);
     case '*' :
          return (b*a);
     case '/' :
          return (b/a) ;
     }
}     
     
int chkoperand(char ch)
{
    if(ch>=48 && ch<=57 )
    return 1;
    else
    return 0;
}

int main()
{
    struct stack *s;
    s=createstack();
  
    char pe[]="234+*5-";
    int i=0;
    
    while(pe[i]!='\0')
    {
         char ch=pe[i];
         int op=chkoperand(ch);
         if(op==digit)
         {
           push(s,(ch-48));
         }
         else if(op==operator)
         {
              int a=pop(s);
              int b=pop(s);
              push(s,evaluate(a,b,ch));
         }
         i=i+1;
    }
    printf("%d",pop(s) );
    getch();
}
