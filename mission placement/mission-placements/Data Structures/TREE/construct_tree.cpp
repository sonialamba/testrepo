#include<stdio.h>
#include<conio.h>
#include"stringlib.c"


char *xcpy(char *s,char *d,int start,int end)
{
     char *p=d;
     while( start <= end )
     {
            *d++  = *(s+start) ;
            start++;
     }
     *d='\0';
     return p;
}
   
   
int position(char *s,char x)
{
    int i=0;
    while( *(s+i) )
    {
        if (  *(s+i)==x )
           return i;
        i++;      
    }
    return -1;
}
    
    
void disp(char s[][20])
{
           int i=0;
           for(i=0 ; i<12 ; i++)
           {
           printf(" %d %s ",i,s[i]);
           printf("\n");
           }
}
           

int main()
{
    
    char pre[]="jcbadefigh";
    char in[]="abcedfjgih";
    char tree[20][20]={0};
    int i,j,p;
    int n=xstrlen(in)-1;
    int level=0;
    
    xcpy(in,tree[0],0,n);
    level=1;
    for( i=0 ; i<=n ; i++ )
    {
         for( j=0 ; j<=level ; j++ )
         {
              p=position(tree[j],pre[i]);
              if( p!=-1)
              break;
         }
        
        int len=xstrlen(tree[j])-1;    
        xcpy(tree[j],tree[2*j+1],0,p-1);
        xcpy(tree[j],tree[2*j+2],p+1, len );
        xcpy(tree[j],tree[j],p,p);
        level=2*j+2;
        printf("%d",level);
    }
    
    disp(tree);
 
     
    getch();
}
