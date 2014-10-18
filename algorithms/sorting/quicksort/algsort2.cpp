#include <cstdio>
#define FIN "algsort2.in"
#define FOUT "algsort2.out"
#define MAXN 500005

using namespace std;

class QuickSort {

     public:

     int vec[ MAXN ], 
         N;

     QuickSort() {

        scanv();  
     }

     void scanv() {

          freopen(FIN, "r", stdin); 

          scanf("%d", &N);

          for(int i = 0; i < N; i++) {

              scanf("%d", &vec[i]);
              
          }

          fclose( stdin );
     };


     void print() {

          freopen(FOUT, "w", stdout); 

          for(int i = 0; i < N; i++) {

              printf("%d ", vec[i]);
              
          }

          fclose( stdout );
     };

     void action() {

          _quicksort(0, N - 1);
     }
      
 
     private:

     void _quicksort(int li, int ls) {

            int i,
                j,
                x,p;

                i = li;
                j = ls;
                p = vec[ (li+ls) >> 1 ];  

                while(i<=j) {

                      while(vec[i]<p) {
                            i++; 
                      }

                      while(vec[j]>p) {
                            j--; 
                      }

                      if(i<=j) {
 
                           x = vec[i]^vec[j]; vec[i] = x^vec[i]; vec[j] = x^vec[j];
                           i++;j--;                            
                      } 
                } 

                if(li<j) _quicksort(li,j);

                if(i<ls) _quicksort(i,ls);
      }       

};

int main() {

    QuickSort q;
    
    q.action();    
    q.print();

    return(0);
}