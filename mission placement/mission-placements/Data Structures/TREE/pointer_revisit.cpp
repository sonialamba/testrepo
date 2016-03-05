#include<stdio.h>
#include<conio.h>

void change(int *p)
{
     int b=20;
     p=&b;
     printf("%x ",p);
}

int main()
{
    int a=10;
    int *p=&a;
    printf("%x ",p);
    change(p);
    printf("%x ",p);
      printf("%d ",a);
    getch();
}
