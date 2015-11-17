#include <istream>
#include <fstream>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define MAXN 500005

int *v, 
    n;

using namespace std;

void read() {

     int i; 

     ifstream fin(FIN);

     fin>>n;

     v = new int[ n ];

     for(i = 0; i < n; ++i) fin>>v[i];

     fin.close();
}

void divideEtImpera(int lo, int hi) {
    
     if(lo == hi) return;

     int m = (lo + hi) >> 1;

     divideEtImpera(lo, m);

     divideEtImpera(m+1, hi);

     int i = lo, 
         j = m + 1,
         k = lo,
         it, 
         *aux;

     aux = new int[hi-lo+1];

     for(it = lo; it <= hi; ++it) aux[ it - lo ] = v[ it ];

     while(i <= m && j <= hi ) {

           if(aux[ i - lo ] < aux[ j - lo ]) v[k++] = aux[ i++ - lo]; 

                      else  
                                             v[k++] = aux[ j++ - lo]; 
     }

     while(i<=m) v[k++] = aux[ i++ - lo]; 

     while(j<=hi) v[k++] = aux[ j++ - lo];

     delete [] aux;
     
}

void write() {

     int i;

     ofstream fout(FOUT);

     for(i = 0; i < n; ++i) fout<<v[i]<<" ";

     fout.close();
}

int main() {

    read();
    divideEtImpera(0, n - 1);
    write();

    return(0);  
}