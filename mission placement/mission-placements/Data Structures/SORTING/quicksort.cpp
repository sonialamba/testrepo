#include<stdio.h>
#include<conio.h>
#define minsize 2


void disp(int list[] , int l , int n )
{
     for(int i = l ; i <= n ; i++)
     {
          printf("%d " , list[i] );
     }
     printf("\n");
}


void swap( int list[] , int left , int right )
{
     int temp = list[left];
     list[left] = list[right];
     list[right] = temp;

         printf("->");
         disp(list,left,right);
}

void medianleft( int list[] , int left , int right )
{    
     int mid = (left + right ) / 2;
     if( list[ left ] > list[ mid ] )
         swap(list , left , mid ) ;
     if( list[left] > list[ right ] )
         swap(list , left , right );
     if( list[ mid ] > list [ right ] )
         swap(list , mid , right );
     
     swap( list , left , mid );

}

void quickinsertion(int list[] , int start , int last )
{
     
     for(int i = start ; i <= last ; i++)
     {
          int curr = i - 1 ;
          while( curr >= start && list[curr] > list[curr+1] )
          {
                 swap(list , curr , curr+1 );
                 curr--;
          }
     }
}

void quicksort(int list[] , int left , int right )
{
     if( (right - left) > minsize )
     {    
          
          printf("x");
         medianleft(list , left , right );
         int pivot = list[left];
         int sortleft = left + 1;
         int sortright = right;
         while( sortleft <= sortright )
         {
                while( list[sortleft] < pivot )
                       sortleft++;
                while( list[sortright] > pivot ) 
                       sortright--;
                
                if( sortleft <= sortright )
                {   
                
          printf("y");
                    swap(list , sortleft , sortright );
                    sortleft++;
                    sortright--;
                }
         }
         printf("z");
         swap(list , left , sortleft-1 );
         
         disp(list,left,right);
         if( left < sortright )
             quicksort(list , left , sortright-1 );
         if( sortleft < right )
             quicksort(list , sortleft , right );
     }
     else
     {
         quickinsertion(list , left , right );
         
     }
}
             
         


int main()
{
    
    int list[12]={ 18 , 86 , 91 , 43 , 41 , 41 , 174 , 43 , 762 , 45 , 84 , 22 } ;
   
   
 //  int list[6] = { 50 , 55 , 58 , 40 , 10 , 20 };
    
    int left = 0 ;
    int right = 11 ;
    
    //disp(list , 4 ,  11);
    
  //  quickinsertion(list,0,11);
    
    quicksort(list , left , right );
    
    disp(list , 0 ,  11);
       
    getch();
}   
    
