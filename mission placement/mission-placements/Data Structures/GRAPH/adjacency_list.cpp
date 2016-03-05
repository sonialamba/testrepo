#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct graph 
{
       int c;
       struct vertex *first;
};

struct vertex
{
       struct vertex *next;
       int d;
       int indegree;
       int outdegree;
       int processed;
       struct arc *firstarc;
};

struct arc
{
       int d;
       struct arc *nextarc;
};

int graphempty(struct graph *g);
arc *findarc(struct arc *list,int k);
graph *creategraph()
{
      struct graph *g=(graph*)malloc(sizeof(graph));
      g->c=0;
      g->first=NULL;
      return g;
}

void insertvertex(struct graph *g,int d)
{
     struct vertex *v=(vertex*)malloc(sizeof(vertex));
     v->indegree=0;
     v->outdegree=0;
     v->processed=0;
     v->d=d;
     v->firstarc=NULL;
     if( g->first == NULL )
     {
         g->first=v;
         v->next=NULL;
     }
     else
     {
         struct vertex *temp=g->first;
         struct vertex *old=NULL;
         while( temp!=NULL && temp->d < d )
         {
                old=temp;
                temp=temp->next;
         }
         
         if( old == NULL )
         {
             g->first=v;
             v->next=temp;
         }
         else
         {
         old->next=v;
         v->next=temp;
         }
     }
     (g->c)++;
}

vertex *searchvertex(struct graph *g,int k)
{
       struct vertex *v=g->first;
       while( v!=NULL )
       {
              if(v->d == k)
                      return v;
              v=v->next;
       }
       return NULL;
}

int deletevertex(struct graph *g,int k)
{
    if( graphempty(g) )
        return -1;
    
    struct vertex *v=searchvertex(g,k);
    
    if( v== NULL )
        return -1;
    
    if( v->indegree > 0 || v->outdegree > 0 )
        return -1;
    
    if( g->first == v )
    {
        g->first = v->next ;
    }
    else
    {    
        struct vertex *temp = g->first ;
        
        while( temp->next != v )
               temp=temp->next;
        temp->next=v->next;
    }
    int d=v->d;
    free(v);
    (g->c)--;
    return d;
}


int insertarc(struct graph *g,int s ,int d )
{
    if( graphempty(g) )
        return -1;
    
    struct  vertex *source=searchvertex(g,s);
    struct  vertex *dest=searchvertex(g,d);
    
    if( source == NULL || dest == NULL )
        return -1;
    
    (source->outdegree) ++ ;
    (dest->indegree) ++ ;
    
    struct arc *x= (arc*) malloc (sizeof(arc));
    x->d = d ;
    
    if( source->firstarc == NULL )
    {
        source->firstarc = x;
        x->nextarc = NULL;
    }
    else
    {
        struct arc *temp=source->firstarc;
        struct arc *old=NULL;
        while( temp!=NULL && temp->d < d )
        {
               old=temp;
               temp=temp->nextarc;
        }
        if( old == NULL )
        {
            source->firstarc = x ;
            x->nextarc = temp ;
        }
        else
        {
            old->nextarc = x ;
            x->nextarc = temp ;
        }
    }
}    


arc *findarc(struct arc *list, int k )
{
    while( list!=NULL )
    {
           if( list->d == k)
               return list;
           list=list->nextarc;
    }
    return NULL ;
}
            
int deletearc(struct graph *g , int s , int d )
{
    struct vertex *source= searchvertex(g,s);
    struct vertex *dest= searchvertex(g,d);
    
    if( source == NULL || dest == NULL )
        return -1;
    
    struct arc *loc;
    
    loc= findarc(source->firstarc, d );
    
    if ( loc == NULL )
       return -1;
    
    if( source->firstarc == loc )
    {
        source->firstarc = loc->nextarc ;
    }
    else
    {
        struct arc *temp=source->firstarc;
        while( temp->nextarc != loc )
               temp=temp->nextarc;
        temp->nextarc=loc->nextarc;
    }
    
    (source->outdegree) -- ;
    (dest->indegree) -- ;
    return d;
}

int graphempty(struct graph *g )
{
    if( g->c == 0 )
        return 1;
    else
        return 0;
} 
    
int findindegree(struct graph *g , int d )
{
    if( !graphempty(g) )
    {
        struct vertex *v= searchvertex(g,d);
        if( v== NULL )
            return -1;
        return v->indegree ;
    }
}

int findoutdegree(struct graph *g , int d )
{
    if( !graphempty(g) )
    {
        struct vertex *v= searchvertex(g,d);
        if( v == NULL )
            return -1;
        return v->outdegree ;
    }
}            

int vertices(struct graph *g )
{
    return g->c;
}

void traverselinks(struct graph *g, int d)
{
    
    struct vertex *v= searchvertex(g,d);
    struct arc *list=v->firstarc;   
    while( list != NULL )
    {
           printf("%d ", list->d );
           list=list->nextarc;
    }
}
    
    
void disp(struct graph *g)
{
     struct vertex *temp=g->first;
     while(temp!=NULL )
     {
       printf("%d ",temp->d );
       temp=temp->next;
     }
}


int main()
{
    struct graph *g=creategraph();
    
    insertvertex(g,10);
    insertvertex(g,20);
    insertvertex(g,30);
    insertvertex(g,15);
    insertvertex(g,40);   
    disp(g);  
    
    insertarc(g,10,20);
    printf(" %d ", findindegree(g,20) );
    printf("%d ", findoutdegree(g,10) );
    printf("%d ", findoutdegree(g,40) );
    
    printf("%d ", vertices(g) );
    
    insertvertex(g,60);   
    
    printf("%d ", vertices(g) );
    
    printf("%d ", deletearc(g,10,20) );
    
    
    printf("%d \n", deletevertex(g,20) );
    
    disp(g);
    
    
    
    getch();
}
    
