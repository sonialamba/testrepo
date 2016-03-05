#include<stdio.h>
#include<conio.h>
#include<string.h>

static char io[]="gdhbeiafjc"; 
static char po[]="abdgheicfj";
 static char t[100][100]={'\0'};
  //This is where the final tree will be stored
   static int hpos=0; void copy_str(char dest[], char src[], int pos, int start, int end); 
   void print_t(); 
   int main(int argc, char* argv[]) 
   { 
       int i,j,k; char *pos; 
       int posn; // Start the tree with the root and its // left and right elements to start off
        for(i=0;i<strlen(io);i++) 
        {
                if(io[i]==po[0]) 
                {
                   copy_str(t[1],io,1,i,i); // We have the root here 
                   copy_str(t[2],io,2,0,i-1); // Its left subtree 
                   copy_str(t[3],io,3,i+1,strlen(io)); // Its right subtree 
                   print_t(); 
                   }
                    } // Now construct the remaining tree 
                    for(i=1;i<strlen(po);i++) 
                    {
                       for(j=1;j<=hpos;j++)
                        { 
                        if((pos=strchr((const char *)t[j],po[i]))!=(char *)0 && strlen(t[j])!=1)
                         {
                          for(k=0;k<strlen(t[j]);k++) 
                          { if(t[j][k]==po[i]){posn=k;break;
                          }
                          }
                         printf("\nSplitting [%s] for po[%d]=[%c] at %d..\n", t[j],i,po[i],posn);
                          copy_str(t[2*j],t[j],2*j,0,posn-1);
                           copy_str(t[2*j+1],t[j],2*j+1,posn+1,strlen(t[j])); 
                           copy_str(t[j],t[j],j,posn,posn); 
                           print_t(); 
                           }
} } 

getch();
} 
// This function is used to split a string into three seperate strings 
// This is used to create a root, its left subtree and its right subtree 
void copy_str(char dest[], char src[], int pos, int start, int end)
 {
      char mysrc[100];
       strcpy(mysrc,src); 
       dest[0]='\0'; 
       strncat(dest,mysrc+start,end-start+1);
        if(pos>hpos)
        hpos=pos;
        printf("hpos %d",hpos);
}
         
          void print_t() 
          {
                int i; for(i=1;i<=hpos;i++) 
                { printf("\nt[%d] = [%s]", i, t[i]); 
                }
                 printf("\n");
           }
