#include<stdio.h>
#include<conio.h>
#include"queue-int.cpp"
#define true 1
#define false 0
void initgraph(int graph[][5],int vertex)
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


void bfs(int graph[][5],int start,int vertex )
{
     struct queue *q=createqueue();
     
     int visited[vertex];
     
     for(int i=0; i<vertex ; i++)
     visited[i]=0;
      
     
     enqueue(q,start);
     visited[start]=1;
     
     while( !queueempty(q) )
     {
            int x=dequeue(q) ;
            printf("%d ", x );
            
            for(int i=0 ; i<vertex ; i++)
            {
              if( graph[x][i]==true && visited[i]==false )
              { 
               enqueue(q,i);
               visited[i]=1;
              } 
            }
     }       
      
}

int main()
{
    
    
    int graph[5][5]={0};
    
    initgraph(graph,5);
    bfs(graph,0,5);
    getch();
}
