#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"sortadt.c"
int reheapup(void **list , int curr )
{
    if ( curr )
    {
         int parent = (curr-1) / 2;
         
         if ( compare(list[curr] , list[parent] )  )
         {    
              exchange(list[curr] , list[parent]);             
              reheapup(list , parent);
         }
    }
    return curr;
}



int reheapdown(void **list, int curr , int last )
{ 
    int left,right,largetree ;
    
    left = 2 * curr + 1;
    
    if( left <= last  )
    {
        right = 2*curr + 2;
        
        if( right <=last )
        {
            if( compare( list[left] , list[ right] ) )
                largetree = left ;
            else
                largetree = right ;
        
        }
        else
                largetree = left ;
                
        if( compare( list[ largetree ] , list [ curr ] ) )
        {
            exchange(list[largetree] , list[curr] );
            reheapdown(list, largetree , last );
        }
    }
    return curr;
}
  
void heapsort(void **list , int n )
{    
    for(int i=0 ; i < n ; i++)
            reheapup(list , i );
    
    for(int i = n-1 ; i > 0 ; i-- )
    {
         exchange(list[0] , list [i] );
         reheapdown(list , 0 , i-1 );
    }
}         

void insert(void **list, int i , int data )
{
     int *x = (int*) malloc ( sizeof(int) );
     *x = data ;
     list[i] = x ;
}
 
     

int main()
{
    
    int n=6;
    
    void **list=(void**) malloc ( sizeof(void*) * n );
    
    int i;
    
    for( i=0 ; i < n ; i++ )
    {
     int x;
     scanf("%d", &x );
     insert(list , i , x );
    }
    
    heapsort( list , n );    
    
    disp( list , n );
    
    getch();

} 
        
