#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int N,i;
    scanf("%d",&N);
    int X[N],sum=0,j,temp;
    for(i=0;i<N;i++)
       { scanf("%d",&X[i]);
         sum+=X[i];
       }
    float mean=(float)sum/N;
    for(i=0;i<N-1;i++)
        for(j=i+1;j<N;j++)
           {
              if(X[i]>X[j])
                  {
                    temp=X[i];
                  X[i]=X[j];
                  X[j]=temp;
              }
    }
    float median;
    if(N%2==0)
          median=(X[N/2]+X[N/2-1])/2.0;
     else
          median=X[N/2];
    int mode=X[0];
    int c=1;
     for(i=0;i<N;i++)
         { temp=0;
        for(j=0;j<N;j++)
           {
              if(X[i]==X[j])
                  temp++;
        }
             if(temp>c)
               {  mode=X[i];
                 c=temp;
               }}
    printf("%.1f\n",mean);
    printf("%.1f\n",median);
    printf("%d\n",mode);
     
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
