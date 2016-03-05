#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int swap(int list[] , int a , int b )
{
    
                         int t = list [ a ];
                         list[ a ] = list[ b ] ;
                         list[ b ] =  t;

}

int reheapup(int list[] , int index )
{
    
    if( index )
    {
        int parent = (index-1)/2 ;
        
        if( list[index] > list[parent] )
        {    
             int temp= list [ index ] ;
             list[index] = list [ parent ];
             list[parent] = temp; 
             return(reheapup(list , parent ));
        }
    }
    return index;       
}


int reheapdown( int list[] , int index , int last )
{
    int leftdata,rightdata,largetree;
    int left = 2 * index + 1 ;
    if( left <= last )
    {   
        leftdata = list[left];
        int right = 2*index + 2;
    
        if( right <=last )
            rightdata = list[right];
        else
            rightdata = - 1;
        
        if( leftdata > rightdata )
         largetree = left;
        else
         largetree = right ;
        
        if( list[ largetree ] > list [ index ] )
        {
            int t = list[index];
            list[index] = list[largetree];
            list[largetree] = t;
            reheapdown(list , largetree , last );
        }
    }
    return index;                                       // place where data moved down
}


void disp(int list[] , int n )
{
     for(int i=0 ; i< n ;i++)
     {
             printf("%d ", list[i] );
     }
     printf("\n");
}

            

int main()
{
    
    int n=6,i;
    
    int list[]={8 , 2 , 5 , 10 , 7 , 15 };
    
    for( i =0 ; i < n ; i++)
    printf("%d " , reheapup(list,i ) );
         
    for( i = n-1 ; i > 0 ; i--)
    {        
             swap(list , 0 , i );
            reheapdown(list,0 , i-1);
    }
    
    disp(list ,  n );    
    
    getch();
}  
