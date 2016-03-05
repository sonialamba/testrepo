#include<stdio.h>
#include<conio.h>


int height(int n)
{
    if(n==1)
     return 1;
    else
     return (height(n-1)+1);
}


int main()
{
    int n=3;
 printf("%d",   height(n) );
 
    getch();
}
