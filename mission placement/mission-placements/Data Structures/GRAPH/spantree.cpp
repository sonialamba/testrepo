#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define true 1
#define false 0
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
       int intree;
       struct arc *firstarc;
};

struct arc
{
       struct  vertex *destv;
       struct arc *nextarc;
       int weight;
       int intree;
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


int insertarc(struct graph *g,int s ,int d , int w )
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
    x->destv = dest ;
    x->weight = w;
    if( source->firstarc == NULL )
    {
        source->firstarc = x;
        x->nextarc = NULL;
    }
    else
    {
        struct arc *temp=source->firstarc;
        struct arc *old=NULL;
        while( temp!=NULL && temp->destv->d < d )
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
           if( list->destv->d == k)
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
    free(loc);
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

void traverselinks(struct arc *list )
{
    
    while( list != NULL )
    {
           printf(" -> %d ", list->destv->d );
           list=list->nextarc;
    }
}
    
    
void disp(struct graph *g)
{
     struct vertex *temp=g->first;
     while(temp!=NULL )
     {
       printf("  %d ",temp->d );
       temp=temp->next;
     }
}


void displaylist(struct graph *g)
{
     struct vertex *v=g->first;
     
     while( v!= NULL )
     {
            printf("v = %d ", v->d );
            traverselinks(v->firstarc);
            printf("\n");
            v=v->next;
     }
}

int createspantree(struct graph *g , int start )
{
    struct vertex *v=g->first;
    
    while( v!= NULL )
    {
           v->intree=0;                         // clear vertex in spantree
           struct arc *x=v->firstarc;
           while( x!=NULL )
           {
                   x->intree=0;                 // clear arc in spantree
                   x=x->nextarc;                
           }
           v=v->next;
    }

    v=searchvertex(g,start);                    // point v to start
    
    int nv=vertices(g);
    int count=0;
    
    v->intree=1;
    count=1;
    
    while ( count != nv )
    {     
          v=g->first;
          int minweight=32767;
          struct arc *minedgeloc=NULL ;
          while( v!= NULL )                       // loop through all vertices
          {
                 if( v->intree == true )
                 {
                     struct arc *varcs=v->firstarc;
                     
                     while( varcs != NULL )
                     {
                            if (  varcs->destv->intree==false && varcs->weight < minweight  )
                            {
                                  minweight=varcs->weight;
                                  minedgeloc=varcs;
                            }
                      varcs=varcs->nextarc;
                     }
                 }
           v=v->next;
          }
          if( minedgeloc!= NULL )
          {   
              minedgeloc->intree = true ;
              minedgeloc->destv->intree = true ;
              printf("%d ", minedgeloc->destv->d );
              count++;
          }
    }
    
} 


int printspantree(struct graph *g,int start )
{
    struct vertex *v = NULL ;
    v=searchvertex(g ,start);                    // point v to start
    int nv=vertices(g);
    int count = 0;
    struct vertex *old=g->first;
    v->processed = true ;
    while( v!=NULL )
    {     
          struct arc *varcs=v->firstarc;
          while( varcs!=NULL )
          {
                 if( varcs->intree == true && varcs->destv->processed == false )
                 {   
                     printf(" source - %d " , v->d );
                     printf(" w-%d ", varcs->weight );
                     v=varcs->destv;
                     printf(" dest - %d ", v ->d) ;
                     v->processed = true ;
                     printf("\n");
                     break;
                 }
            varcs=varcs->nextarc;
          }
          if( varcs == NULL )
          {    
               v=old;
               if( old!=NULL )
                   old=old->next;
          }
     }
               
}
    
int main()
{
    struct graph *g=creategraph();
    
    insertvertex(g,10);
    insertvertex(g,20);
    insertvertex(g,30);
    insertvertex(g,40);
    insertvertex(g,50);   
    insertvertex(g,60);   
    
    
    insertarc(g,10,20,6);
    insertarc(g,20,10,6);
    
    insertarc(g,10,30,3);
    insertarc(g,30,10,3);
    
    insertarc(g,20,40,5);
    insertarc(g,40,20,5);
    
    insertarc(g,30,50,4);
    insertarc(g,50,30,4);
    
    insertarc(g,50,60,5);
    insertarc(g,60,50,5);
    
    insertarc(g,40,60,3);
    insertarc(g,60,40,3);

    insertarc(g,20,30,2);
    insertarc(g,30,20,2);

    
    insertarc(g,30,40,3);
    insertarc(g,40,30,3);

    
    insertarc(g,40,50,2);
    insertarc(g,50,40,2);

    displaylist(g);
    
    createspantree(g,10);
    printf("\n");
    printspantree(g,10);
    getch();
}
    
