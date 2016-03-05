#include<stdio.h>
#include<conio.h>
#include"stackadt.cpp"
#define true 1
#define false 0
void initgraph(int graph[][9],int vertex)
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


void dfs(int graph[][9],int start,int vertex)
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

int shortestpath(int graph[][6],int start , int vertices , int pathlength[] )
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
           incomplete = false ;
           int pathloc = false ;
           int minweight = 32767;
           
           for(int v=0; v < vertices ; v++ )
           {
                    int minlength = pathlength[v] ;
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
                                     pathloc=e;
                                 }
                            }
                        }
                    }
           }
           
           if( pathloc != false )
           {
               intree[pathloc]=1;
               pathlength[pathloc]=minweight ;
           }
    }
    
}

int printpath(int graph[][6] , int pathlength[] )
{
    for(int v=0 ; v < 6 ; v++)
    {
             printf("%d - %d\n", v , pathlength[v] );
            
    } 
}

int main()
{
    
    
    int graph[6][6]={
        
                     {0,6,3,0,0,0},
                     {6,0,2,5,0,0},
                     {3,2,0,3,4,0},
                     {0,5,3,0,2,3},
                     {0,0,4,2,0,5},
                     {0,0,0,3,5,0},
                     
                     };
    
    int pathlength[6];
    shortestpath(graph , 0 , 6 ,  pathlength );
    printf("\n");
    printpath(graph , pathlength);
  
  
    getch();
}
