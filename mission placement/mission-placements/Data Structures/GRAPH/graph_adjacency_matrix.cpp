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
int dfsr(int graph[][9],int start,int vertex,int visited[])
{
        
        printf("%d",start);     
        for(int i = 0 ; i < vertex   ; i++)
        {
             if( visited[i]==false && graph[start][i]==true )
             { 
                          visited[i]=true;   
             }
                                     
        }
}

int main()
{
    
    
    int graph[9][9]={0};
    
    initgraph(graph,9);
    dfs(graph,0,9);
     int visited[9];
     for(int i=0; i<9 ; i++)
     visited[i]=0;
    
    printf("\n");
   // visited[0]=1;
    dfsr(graph,0,9,visited);
    getch();
}
