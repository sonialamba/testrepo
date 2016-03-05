#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node 
{
       int d;
       struct node *next;
};

struct queue
{
       struct node *front;
       struct node *rear;
       int c;
};

queue *createqueue()
{
      struct queue *q=(queue*)malloc(sizeof(queue));
      q->front=NULL;
      q->rear=NULL;
      q->c=0;
      return q;
}

int queueempty(struct queue *q)
{
     if( q->front==NULL)
     return 1;
     else
     return 0;
}

void enqueue(struct queue *q,int d)
{
     struct node *n=(node*)malloc(sizeof(node));
     n->d=d;
     n->next=NULL;
     if( queueempty(q) )
     {
             q->front=n;
     }
     else
     {
             q->rear->next=n;
     }
         q->rear=n;
         (q->c) ++;
}

int dequeue(struct queue *q)
{
    if( queueempty(q) )
    {
        return -1;
    }
    else
    {
        struct node *n;
        n=q->front;
        q->front= n->next;
        if ( q->front == NULL )
             q->rear=NULL;
    
        int d=n->d;
        free(n);
        (q->c)--; 

        return d;
    }
}  

int queueFront(struct queue *q)
{
     if( q->front == NULL )
     return -1;
     else
     q->front->d;
}


int queueRear(struct queue *q)
{
     if( q->rear == NULL )
     return -1;
     else
     q->rear->d;
}
