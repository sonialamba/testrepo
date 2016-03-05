#include<conio.h>
#include<stdio.h>


void swap(int list[] , int a , int b )
{
     int temp = list[a];
     list[a] = list[b];
     list[b] = temp;
}

void disp(int list [] , int n )
{
     for(int i=0 ; i < n ; i++)
     { 
       printf("%d " , list[i] );
     }
     printf("\n");
}
void bubblesort(int list[] , int n )
{
     int i = 0;
     
     for( i = 0 ; i < n - 1 ; i++)
     {
          printf("pass %d \n " , i);
          for(int j = 0 ; j < (n-1)-i ; j++)
          {
               if( list[j] > list[j+1] )
               {
                   swap(list , j , j+1 );
                        disp(list , n);
          
               }
          }
          printf("\n");
     }
 
}

int main()
{
    
    int list[] = { 8 , 22 , 7 , 9 , 31, 19 , 5 , 13};
    
    bubblesort(list , 8 );
    
    getch();
}
