#include <stdio.h>
#define FIN "scmax.in"
#define FOUT "scmax.out"
#define SIZE 100009

int V[ SIZE ],
    L[ SIZE ],
    n;

void input() {

     freopen(FIN,"r",stdin);
     scanf("%d", &n);
     for(int i = 1; i <= n; ++i ) {
         scanf("%d", &V[i]);
     }
}

void dynamic_programming() {

     freopen(FOUT,"w",stdout);

     int i, j, max, pos;

     L[ n ] = 1;

     for(i = n - 1; i >= 1; i--) {

         max = 0;

         for(j = i + 1; j <= n; ++j) {

                 if(V[j] > V[i] && L[j] > max) {

                     max = L[j];
                 }
         }

         L[i] = 1 + max;
     }

     max = L[1];

     pos = 1;
     
     for(int i = 2; i <= n; i++) {

       if (L[i] > max) {

                  max = L[i] ;
                  pos = i;
       }

     }

     printf("%d\n%d ", max, V[pos]);

     for(i = pos + 1; i <= n; i++) {

           if(V[i] > V[pos] && L[i] == max - 1) {

              printf("%d ", V[i]);

              max--;
           }
     }
}

//V: 24 12 15 15 19
int main(int argc, char const *argv[]) {

  input ();
  dynamic_programming ();

  return 0;

}


