#include<stdio.h>
#include<conio.h>
#define max 7
#define root 0
int count=-1;
void reheap(int a[],int i)
{
 if( i!=root)
 {
     int parent=(i-1)/2;
     if( a[i] >  a[parent] )
     {
         int t=a[i];
         a[i]=a[parent];
         a[parent]=t;
         reheap(a,parent);          
     }
 }

}
int heapfull()
{
     if( count == max-1 )
     return 1;
     else
     return 0;
}

void buildheap(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    reheap(a,i);
    }

}

int heapempty()
{
    if( count == -1 )
        return 1;
    else
        return 0;
}

void insertheap(int a[],int k)
{
     if(heapfull())
     return;
     else
     {
         count++;
         a[count]=k;
         reheap(a,count);
     }
}


int reheapdown(int a[],int p)
{
     int leftdata,rightdata,largetree;
     int left=2*p + 1;  
     if( left <= count )
     {
         int leftdata=a[left];
         int right=2*p + 2;
         if( right <= count )
           rightdata=a[right];
         else
           rightdata=-1;
          
         if( leftdata > rightdata )
             largetree=left;
         else
             largetree=right;
             
         if( a[p] < a[largetree] )
         {
            int t=a[p];
            a[p]=a[largetree];
            a[largetree]=t;
            getch();
            return(reheapdown(a,largetree));
         }   
     }
     return p; 
}     

void print(int a[])
{
     for(int i=0;i<=count;i++)
     printf("%d ",a[i]);
     printf("\n");
}

           
int deleteheap(int a[])
{
     if( heapempty() )
         return -1;
     else
     {
         a[0]=a[count];
         a[count]=-1;
         count--;
         print(a);
         printf("%d ", reheapdown(a,0) );
         return 1;
     }     
}



int main()
{
    int a[7]={8,19,23,32,45,56,78};
  
    
    insertheap(a,8);
    insertheap(a,19);
    insertheap(a,23);
    insertheap(a,32);
    
    insertheap(a,45);
    
    insertheap(a,56);
    
    
    print(a);
    
    deleteheap(a);
    
    print(a);
    getch();
}
