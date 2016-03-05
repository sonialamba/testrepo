#include<stdio.h>
#include<conio.h>

int swap(int list[]  , int x , int y )
{
    int t= list[x];
    list[x]= list[y];
    list[y] = t;
}

int sequentialsearch(int list[] , int end , int target )
{
    int i= 0;
    while( i < end && list[i] != target )
           i++;
    
    if( i  == end )
        return -1;
    else
        return i ;
}

int sentinelsearch(int list[] , int end , int target )
{
    list[ end ] = target ;
    int i=0;
    while( list[i] != target )
           i++;
    
    if( i == end )
        return -1;                     // sentinel entry
    else
        return i;
}        


int probablesearch(int list[] , int end , int target )
{
    int i=0;
    while( i < end && list[i] != target )
           i++;
    
    if( i == end )
        return -1;
    else
    {
        if( i != 0 )
        {
            swap( list , i  , i-1 ) ;
        }
        return i;
    }     
}


int orderedsearch(int list[] , int end , int target )
{   
    if( target > list[ end -1 ] )
        return -1;
        
    int i=0;
    while( i < end && list[i] < target )
           i++;
    
    if( list[i] == target )
        return i;
    else
        return -1;
}
    

int binarysearch(int list[] , int left , int right , int target )
{
    
    while ( left <= right )
    {
        int mid = (left + right) / 2 ; 
        if( list[ mid ] == target )
            return mid ;
        else if( list[mid] < target )
             left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
     
    
int main()
{
    
    int list[10]={ 1,2,3,10,20,40,90 }; 
    
     printf("%d ",     probablesearch(list , 7 , 10 ) );
     printf("%d ",    orderedsearch(list , 7 , 0 ) );
     printf("%d ",    binarysearch(list , 0 ,  6 , 90 ) );
    
    
    
    
    
    getch();
}
