#include<stdio.h>
#include<conio.h>
#define max 7
#define root 0

void reheap(int a[],int i)
{
 
 if( i!=root)
 {
     int parent=(i-1)/2;
     if( a[i] >  a[parent] )
     {
         int t=a[i];
         a[i]=a[parent];
         a[parent]=t;
         reheap(a,parent);          
     }
 }

}

void buildheap(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    reheap(a,i);
    }

}


void insertheap(int a[],int n)
{
     

}

void print(int a[])
{
     for(int i=0;i<max;i++)
     printf("%d ",a[i]);
     printf("\n");
}

int main()
{
    int a[7]={8,19,23,32,45,56,78};
    buildheap(a,7);
    print(a);
    getch();
}
