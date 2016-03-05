#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list 
{
       int data ;
       struct list *next;
};


int insertdata(struct list l[] , int loc , int d )
{
    if( l[loc].data != -1 )
    {
        l[loc].data = d;
        l[loc].next = NULL;
    }
    else
    {
        struct list temp;
        struct list *n=(list*)malloc(sizeof(list));
        temp = l[loc];
        while(temp.next != NULL )
        {
           temp = temp.next ;
        }
        temp.next = n ;
        n.next = NULL ;
    }
}


int main()
{
    
    struct list l[10];
    int i;
   
   for( i = 0 ; i < 10 ; i++)
   insertdata( l , i  , i) ;
    
   for( i = 0 ; i < 10 ; i++) 
         printf("%d " , l[i].data );
   
     
    getch();

} 
         
