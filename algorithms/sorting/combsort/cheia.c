#include <stdio.h>
#include <malloc.h>
#define FIN "algsort.in"
#define FOUT "algsort.out"

void* read(){
      int i,n,*p;
      freopen(FIN, "r", stdin);
      scanf("%d",&n);
      //allocated space in heap
      p = (int*)malloc(sizeof(int)*(n+1));
      p[0] = n;  
      for(i = 1; i <= n;  ++i) {
           scanf("%d", p + i);
      }

      return p;
}

void write(int *p) {

     freopen(FOUT, "w", stdout);

     int i, n = p[0];

     for(i = 1; i <= n; ++i) {

             printf("%d ", *(p + i)); 
     }
}

void c_s(int *p) {

     int n = p[0];
     float shrinkFactor = 1.3; 
     int swapped = 0, i, gap = n;
 
     while(gap>1 || swapped) {

           swapped = 0;
           if(gap > 1) gap = gap / shrinkFactor;

           for(i = 1; (i + gap) < n + 1; ++i) {
                   if(p[i] > p[i+gap]) {
                      int holder = p[i];
                          p[i] = p[i+gap];
                          p[i+gap] = holder;
                          swapped = 1; 
                   }
           } 
     }
        
}

int main() {

    int *p,i;
    p = (int*)read();
    c_s(p);
    write(p);

    //clean up 
    free(p);   
    return(0);
}
