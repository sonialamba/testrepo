#include<stdio.h>
#include<conio.h>



void disp(int list [] , int n )
{
     for(int i=0 ; i < n ; i++)
     { 
       printf("%d " , list[i] );
     }
     printf("\n");
}

int copyarray(int list[] , int temp[] , int left , int n )
{
    for( int i = 0 ; i < n ; i++  )
    {
         list[left] = temp[i] ;
         left++;
    }
    disp(temp , n);
}

int merge(int list[] , int start1 , int end1 , int start2 , int end2)
{   
    int size=end2-start1 ;
    int temp[ size + 1];
    int left1= start1;
    int right1=end1;
    int left2= start2;
    int right2=end2;
    
    int index = 0; 
    
    while( left1 <= right1 && left2 <=right2)
    {
           if( list[left1] <= list[left2] )
           {
               temp[ index ] = list[left1];
               left1++;
           }
           else
           {
               temp[ index ] = list[left2];
               left2++;
           }
       index++;
    }
    
    while( left1 <= right1 )
    {
           temp[index] = list[left1];
           index++;
           left1++;
    }
    
    while( left2 <= right2 )
    {
           temp[index] = list[left2];
           index++;
           left2++;
    }
    copyarray(list , temp ,  start1 ,  index );
}
    

int mergesort(int list[] , int left , int right )
{
    if( left < right )
    {
        int mid = (left + right ) / 2;
        mergesort(list , left , mid );
        mergesort(list , mid+1 , right );
        merge(list , left , mid , mid+1 , right );
    }
}


int main()
{
    
    int list[]={ 10 , 90 , 80 , 70 , 60 , 50 , 100 } ;
    
    mergesort(list , 0 , 6 );
    
    disp( list , 7 );
    
    getch();
}
