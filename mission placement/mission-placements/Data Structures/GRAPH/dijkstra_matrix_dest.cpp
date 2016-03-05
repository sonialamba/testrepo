#include<stdio.h>
#include<conio.h>
#include"stackadt.cpp"
#define true 1
#define false 0
void initgraph(int graph[][11],int vertex)
{
     int i=0;
     int source,dest,arcs;
     
     
     for(int i=0; i<vertex ; i++)
     for(int j=0; j<vertex ; j++)
             graph[i][j]=0;
     
     printf("\n enter no of arcs ");
     scanf("%d",&arcs);
     
     for(i=0;i<arcs;i++)
     {
       printf("enter source dest");
       scanf("%d %d", &source , &dest );
       graph[source][dest]=1;
       graph[dest][source]=1;
     }
       
           
}


void dfs(int graph[][11],int start,int vertex)
{
     struct stack *s=createstack();
     int visited[vertex];
     
     for(int i=0; i<vertex ; i++)
     visited[i]=0;
     
     push(s,start);
     visited[start]=1;
     while( !emptystack(s) )
     {
            int x=pop(s);
            printf("%d",x);
            for(int i=vertex-1 ; i>=0 ; i--)
            {
              if( graph[x][i]==true && visited[i]==false )
              { 
               push(s,i);
               visited[i]=1;
              } 
            }
     }
     
}            

int shortestpath(int graph[][11],int start , int dest , int vertices , int pathlength[] )
{
    int intree[ vertices ];
    for(int v=0 ; v < vertices ; v++)
    {
            pathlength[v]=0;
            intree[v]=0;
    }
    
    intree[start] = true ;                                                  // enter starting point
    int incomplete = true ;                                                 
    
    while( incomplete )                                                    // while all vertex not visited
    {      
           int newpathlength=32767;
           int pathloc = false ;
           
           for(int v=0; v < vertices ; v++ )
           {
                    int minweight = 32767;
                    int minlength = pathlength[v] ;
                    int minedgeloc = false ;
                    if( intree[v] == true )
                    {   
                        for(int e=0; e < vertices ; e++ )
                        {
                            if( graph[v][e] != false && intree[e]== false )
                            {    
                                 incomplete = true ;                            // tree is incomplete
                                 if( graph[v][e] < minweight )
                                 {
                                     minweight = graph[v][e];
                                     minedgeloc=e;
                                 }
                            }
                        }
                    }
                    
                    if( minweight + minlength < newpathlength )
                    {
                        newpathlength= minweight + minlength ;
                        pathloc = minedgeloc ;             
                    }
           }
           
           if( pathloc != false )
           {
               pathlength[pathloc]=newpathlength;
               intree[pathloc]=1;
               if( pathloc == dest )
                   incomplete = false ;
               else
                   incomplete = true ;
           }
    }
    
}

int printpath(int graph[][11] , int pathlength[] )
{
    for(int v=0 ; v < 11 ; v++)
    {
             printf("%d - %d\n", v , pathlength[v] );
            
    } 
}

int main()
{
    
    
/*    int graph[6][6]={
        
                     {0,6,3,0,0,0},
                     {6,0,2,5,0,0},
                     {3,2,0,3,4,0},
                     {0,5,3,0,2,3},
                     {0,0,4,2,0,5},
                     {0,0,0,3,5,0},
                     
                     };
    */
     int graph[11][11]={
        
                     {0,17,0,8,0,2,0,9,0,6,0},
                     {17,0,2,0,4,5,1,0,6,0,90},
                     {0,2,0,9,0,0,2,0,0,7,0},
                     {8,0,9,0,0,0,0,0,0,0,0},
                     {0,4,0,0,0,0,0,0,0,0,0},
                     {2,5,0,0,0,0,5,0,0,7,0},
                     
                     {0,1,2,0,0,5,0,0,0,0,0},
                     
                     {9,0,0,0,0,0,0,0,56,0,0},
                     
                     
                     {0,6,0,0,0,0,0,56,0,0,0},
                     
                     
                     
                     {6,0,7,0,0,7,0,0,0,99,0},
                    
                     {0,90,0,0,0,0,0,0,0,0,0},
                    
                     };
    
    int pathlength[11];
    shortestpath(graph , 0 , 10 , 11,  pathlength );
    printf("\n");
    printpath(graph , pathlength);
  
  
    getch();
}
