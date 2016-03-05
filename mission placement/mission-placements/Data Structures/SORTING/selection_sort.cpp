#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"sortadt"

void selectionsort( void  **list , int n   )
{
     
     for ( int i=0 ; i < n-1 ; i++ )
     {
         void *min= list + i ;
         for (int j= i + 1 ; j < n ; j++ )
         {
             if ( compare( min  , list + j  ) > 0 )
             {
               min = list + j ;   
             } 
         }
         exchange( min , list + i );
     }
}

int main()
{
    int n=6;
    
    void **list=(void**) malloc ( sizeof(void*) * n ) ;
    for( int i = 0 ; i < 6 ; i++)
    {     
       scanf("%d" ,   (int*)(list + i) ) ; 
    }
    
    
    selectionsort( list , n ) ; 
    
    
    for(int i = 0 ; i < 6 ; i++)
    {     
       printf(" %d ",   * ( (int*)(list + i) ) );
    }
    
    
    getch();
}
