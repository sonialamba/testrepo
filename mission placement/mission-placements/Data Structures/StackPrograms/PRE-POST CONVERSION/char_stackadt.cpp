#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
       char d;
       struct node *next;
};

struct stack
{
       int c;
       struct node *top;
};

stack* createstack(void)
{
       struct stack *s=(stack*)malloc(sizeof(stack));
       if(s)
       {
            s->c=0;
            s->top=NULL;
       }
       return s;
}
       


void push(struct stack *s,char d)
{
     struct node *n=(node*)malloc(sizeof(node));
     n->d=d;
     n->next=s->top;
     s->top=n;
     (s->c)++;
}

char stacktop(struct stack *s)
{
    if(s->c!=0)
    return (int) s->top->d;
    else
    return -1;
}

int emptystack(struct stack *s)
{
    if(s->c==0)
    return 1;
    else
    return 0;
}

char pop(struct stack *s)
{
    if(s->c==0)
    return -1;
    else
    {
         struct node *n;
         n=(s)->top;
         s->top=n->next;
         char d=n->d;
         free(n);
         (s->c)--;
         return d;
    }
}

int stackcount(struct stack *s)
{
    return s->c;
}

void destroystack(struct stack *s)
{
     struct node *temp;
     while(s->top!=NULL)
     {
     temp= s->top;
     s->top=temp->next;
     free(temp);
     }
}

void disp(struct stack *s)
{
     struct node *t=s->top;
     printf("STACK TRACE :");
     while(t!=NULL)
     {
        printf("%c ",t->d);
        t=t->next;
     }
     printf("\n");
}
int main()
{
    struct stack *s;
    s=createstack();
    
    int n=15;

          
    getch();
}
