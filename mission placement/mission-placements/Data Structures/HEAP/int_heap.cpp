#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
typedef struct heap
{
        int size;
        int last;
        int maxsize;
        int *heapary;
};

void disp(struct heap *h)
{
     int i=0;
     
     while( i < h->size)
     {
            printf("%d ", h->heapary[i] );
            i++;
     }
     printf("\n");
} 

heap* createheap(int n)
{
  int x;                                    // memory loc
  if(n%2==0)
     x=(int) pow(2,ceil( log2(n+1)) ) - 1 ;
  else
     x=(int) pow(2,ceil( log2(n) ) ) - 1 ;
     
     heap *h=(heap*) malloc (sizeof( heap) );
     h->maxsize=x;
     printf("%d",x);
     h->heapary=(int*)malloc(sizeof( x * sizeof(int) ) );
     h->size=0;
     h->last=-1;    
     return h;
}

int reheapup(heap *h,int index)
{
    if ( index )
    {
         int parent=(index-1)/2;
         if ( h->heapary[index] > h->heapary[parent] )
         {
              int t=h->heapary[index];
              h->heapary[index]=h->heapary[parent];
              h->heapary[parent] = t;
              
              return( reheapup(h,parent) );
         }
    }
    else
              return index;                            // location where child is moved 
}

int insertheap(heap *h,int k)
{
     if( h->size == h->maxsize )
      return -1;
     if( h->size == 0 )
     {
         
         ++(h->last);
         h->heapary[h->last] = k;
         ++(h->size);
         
     }
     else
     {
         ++(h->last);
         h->heapary[ h->last ] = k;                     // h->heapary[last] *(h->heapary + last)
         ++(h->size);
         reheapup(h,h->last);
     }
}

int reheapdown(heap *h,int r,int last)
{
    int leftdata,rightdata,left,right,largetree;
    left=2*r + 1 ;
    if( left <= last )
    {
        leftdata=h->heapary[left];
        right=2*r+2;
        if(right <= last )
           rightdata=h->heapary[right];
        else
            rightdata=-1;
        
        if( leftdata > rightdata )
            largetree=left;
        else
            largetree=right;
            
        if( h->heapary[r] < h->heapary[largetree] )
        {
            int t=h->heapary[r];
            h->heapary[r]=h->heapary[largetree];
            h->heapary[largetree] = t;
           return ( reheapdown(h,largetree,last) ) ;
        }
    }
    return r;
}
int deleteheap(heap *h)
{
    if( h->size==0)
        return -1;
    else
    {
        int t=h->heapary[0];
        h->heapary[0]=h->heapary[h->last];
        --(h->last);
        --(h->size);
        printf("pos = %d ", reheapdown(h,0,h->last) );
        
        return t;
    }
}


int main()
{
 
   int n=7;
   struct heap *h=NULL;
   h=createheap(n);
   insertheap(h,10);
   insertheap(h,20);
   insertheap(h,30);
   insertheap(h,40);
   insertheap(h,50);
   insertheap(h,60);
   insertheap(h,70);
   insertheap(h,80);
   disp(h);
   
   deleteheap(h);  
   
   disp(h);
   
  getch();
}
