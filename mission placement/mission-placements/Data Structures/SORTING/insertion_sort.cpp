#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void exchange( void *a , void *b )
{
     int x = * ( (int*) a );
     
     * ( (int*) a ) = *( (int*) b );
     
     * ( (int*) b ) = x ;
      
}

int compare( void *a , void *b )
{
     
    if(  * ( (int*) a ) > *( (int*) b ) )
         return 1;
    else
        return 0;
     
}
void insertionsort(void **list , int n )
{
     int i;
     
     for( i =1 ; i < n ; i++)
     {
          int j=i-1;
          while( j >= 0 && compare( list[ j ] ,  list [ j + 1 ] ) )
          {
                 exchange(list[j] , list[j+1] );
                 j--;
          }
     }
     printf("x");
     getch();
}


   
void disp(void **list , int n )
{    
     printf("\n");
     for( int i = 0 ; i < n ; i++ )
          printf("%d " ,   * ( (int*) *( list + i ) ) );   // list[i]
     
}

int main()
{
    
    int n = 6;
    void **list;
    for( int i = 0 ; i < n ; i++ )
    {    
         int *x=(int*) malloc (sizeof( int ) ) ;
         scanf("%d" , x );
         *(list + i ) = x ;
    }
    
    insertionsort(list , n );
    
    printf("x");
    
    disp(list , n );
    
    
    printf("x");
    
    getch();
} 
