#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct heap
{
       
       int a[7];
       char b[5];
       int last;
       int size;
}; 

int main()
{
    struct heap *h=(heap*)malloc(sizeof(heap));
    
    h->a[0]=20;
    
    printf("%d",h->a[0]);
    
 
    getch();
}
