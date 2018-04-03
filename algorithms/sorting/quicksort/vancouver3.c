#include <stdio.h>

void _quicksort(int *p, int lo, int hi) {

     int piv = p[ (lo + hi) >> 1], i = lo, j = hi;      

     while(i <= j) {

           while(p[i]<piv) i++;

           while(p[j]>piv) j--;

           if(i<=j) {

                int x = p[i]^p[j];
                    p[i] = p[i]^x;
                    p[j] = p[j]^x;
                    i++;
                    j--;
           } 

           if(lo<j) _quicksort(p, lo, j);

           if(hi>i) _quicksort(p, i, hi);
     } 

}

void quicksort(int *p, int n) {

     _quicksort(p, 0, n - 1);
      
}

int main() {

    const char *fin = "algsort.in";
    const char *fout = "algsort.out";

    int v[50005],
        n,
        i;   

    freopen(fin,"r",stdin);

    freopen(fout,"w",stdout);

    scanf("%d", &n);


    //for(i = 0; i < n; ++i) scanf("%d", v + i); the same thing
    for(i = 0; i < n; ++i) scanf("%d", &v[i]);

    quicksort(v, n);

    for(i = 0; i < n; ++i) printf("%d ", *(v + i));


 return(0);
}