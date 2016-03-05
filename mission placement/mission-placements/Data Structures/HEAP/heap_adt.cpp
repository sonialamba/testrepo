#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct heap
{
       int a[7];
       int last;
       int size;
       int maxsize;
}; 


heap* createheap(int max)
{
      struct heap *h;
      h=(heap*)malloc(sizeof(heap));
      h->last=-1;
      h->size=0;
      h->maxsize=max;
      return h;
}

int reheapup(struct heap *h,int index)
{           
     if( index==0 )
         return h->a[index];                // return new parent
     else
     {
         int parent=(index-1)/2;
         if( h->a[index] > h->a[parent] )
         {
             int t=h->a[index];
             h->a[index]=h->a[parent];
             h->a[parent]=t;
             return(reheapup(h,parent));
         }
     }                
}

int insertheap(struct heap *h,int k)
{
    if( h->size == h->maxsize )
        return -1;
    
    if( h->size == 0 )
    {
        h->size=1;
        h->last=0;
        h->a[h->last]=k;
    }              
    else
    {
       ++(h->last);
       ++(h->size);
       h->a[h->last]=k;
       reheapup(h,h->last);
    }
    return 1;
}

void disp(struct heap *h)
{
     int i=0;
     
     while( i < h->size)
     {
            printf("%d ", h->a[i] );
            i++;
     }
     printf("\n");
} 

int main()
{
    
    struct heap *h=createheap(7);
    
    insertheap(h,8);
    insertheap(h,19);
    insertheap(h,23);   
    insertheap(h,32);
    insertheap(h,45);
    insertheap(h,56);
    insertheap(h,78);
    
    disp(h);
    
    getch();
}
