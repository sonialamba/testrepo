#include<stdio.h>
#include<conio.h>

void insertionsort(int list[] , int n )
{
     
     for( int i = 1 ; i < n ; i++)
     {
          int j=i-1;
          
          while( j>=0 && list[j] > list[j+1] )
          {
                 int t = list[j];
                 list[j] = list[j+1];
                 list[j+1] = t;
                 j--;
          }
     }
}

int main()
{
    
    int list[6]={10,3,45,1,100,190};
    
    insertionsort(list , 6 );

    for(int i=0 ; i < 6 ; i++)
    {
            printf("%d ", list[i] );
    }
        
    getch();
}
    
    
