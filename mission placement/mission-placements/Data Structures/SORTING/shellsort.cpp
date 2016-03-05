#include<stdio.h>
#include<conio.h>

void disp(int list[] , int n )
{
     for(int i=0 ; i< n ;i++)
     {
             printf("%d ", list[i] );
     }
     printf("\n");
}


int swap(int list[] , int a , int b )
{
    
                         int t = list [ a ];
                         list[ a ] = list[ b ] ;
                         list[ b ] =  t;

}

int shellsort(int list[] , int n )
{
    
    int inc = n/2 ;
    while( inc )
    {
           int curr = inc;
           
           while( curr < n )
           {
                  int walker =  curr - inc ;
                  
                  while( walker>=0 && list[ walker ] > list[walker + inc ] )
                  {
                         swap(list , walker , walker+inc );
                         walker = walker - inc;
                  }
                  curr++;
           }
           inc = inc/ 2;
    }
}


int main()
{
    
    int list[]= { 77 , 62 , 14 , 9 , 30 , 21 , 80 , 25 , 70 , 55 };
    
    shellsort( list , 10 );
    
    disp( list , 10 );
    
    getch();
}
