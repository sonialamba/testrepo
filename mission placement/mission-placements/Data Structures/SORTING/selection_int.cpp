#include<stdio.h>
#include<conio.h>

void selectionsort(int list[] , int n )
{
     for( int i=0; i < n-1 ; i++ )
     {
          int min=list[i] ;
          int pos=i;         
          for(int j = i+1 ; j<n ; j++ )
          {
                 if( min > list[j] )
                 {
                     min = list[j] ;
                     pos = j;
                 }
          }
          
          int t = list[i];
          list[i] = min ;
          list[pos] = t;
     }
}
          
                  
     

int main()
{
    int list[]= { 20,60,70,80,90,100 };
    
    selectionsort(list, 6 );
    
    for( int i=0 ; i < 6 ; i++ )
    printf("%d ",list[i] );
    
    getch();
}
