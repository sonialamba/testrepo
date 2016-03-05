#include<stdio.h>
#include<conio.h>
#define minsize 0


void disp(int list[][2] , int l , int n )
{
     for(int i = l ; i <= n ; i++)
     {
          printf("%d %d\n" , list[i][0] , list[i][1] );
     }
     printf("\n");
}


void swap( int list[][2] , int left , int right )
{
     int temp = list[left][0];
     list[left][0] = list[right][0];
     list[right][0] = temp;

     int temp1 = list[left][1];
     list[left][1] = list[right][1];
     list[right][1] = temp1;


}

void medianleft( int list[][2] , int left , int right )
{    
     int mid = (left + right ) / 2;
     if( list[ left ][0] > list[ mid ][0] )
         swap(list , left , mid ) ;
     if( list[left][0] > list[ right ][0] )
         swap(list , left , right );
     if( list[ mid ][0] > list [ right ][0] )
         swap(list , mid , right );
     
     swap( list , left , mid );
}

void quickinsertion(int list[][2] , int start , int last )
{
     
     for(int i = start ; i <= last ; i++)
     {
          int curr = i - 1 ;
          while( curr >= start && list[curr][0] > list[curr+1][0] )
          {
                 swap(list , curr , curr+1 );
                 curr--;
          }
     }
}


int performsort(int list[][2] , int left , int right )
{
       medianleft(list , left , right );
         int pivot = list[left][0];
         int sortleft = left + 1;
         int sortright = right;
         while( sortleft <= sortright )
         {
                while( list[sortleft][0] < pivot )
                       sortleft++;
                while( list[sortright][0] > pivot ) 
                       sortright--;
                
                if( sortleft <= sortright )
                {   
                    swap(list , sortleft , sortright );
                    sortleft++;
                    sortright--;
                }
         }
         
         swap(list , left , sortleft-1 );
         return sortleft-1;
}       


void quicksort(int list[][2] , int left , int right )
{
     if( (right - left) > minsize )
     {
         int p = performsort(list,left,right);
         if( left < p-1 )
             quicksort(list , left , p-1 );
         if( right > p+1 )
             quicksort(list , p+1 , right );
     }
     else
     {
         quickinsertion(list , left , right );
     }
}
             
         


int main()
{
    
    int list[6][2]={ {18, 1 } , { 18 , 2 } , { 18 , 3}  , { 18 , 4 } , { 18 , 5 } , {18 , 6} };
   
    int left = 0 ;
    int right = 5 ;
    
    //disp(list , 4 ,  11);
    
    //quickinsertion(list,1,9);
    
    quicksort(list , left , right );
    
    disp(list , 0 ,  5);
       
    getch();
}   
    
