#include <cstdio>
#include <fstream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

vector<unsigned int> v;
int n;

class QuickSort {

      public:

      vector<unsigned int> arr;
      int n;
   
      QuickSort(vector<unsigned int> vec,int num) {
 
                arr = vec; n = num;
                _QuickSort(0, n - 1);
      };      

      void print() {

                ofstream o(FOUT);

                for(int j = 0; j < n; j++) o<<arr.at( j )<<" ";

                o.close();
      }       

      void print2() {

                freopen(FOUT, "w", stdout);

                for(vector<unsigned int>::iterator it = arr.begin(); it != arr.end() ;++it) printf("%d ", *it);

                fclose( stdout );
      }       

      void print3() {

                freopen(FOUT, "w", stdout);

                for(int j = 0; j < n; j++) printf("%d ", arr[ j ]);

                fclose( stdout );
      } 

      private: 
      void _QuickSort(int li, int ls) {

           int i,
               j,
               piv;

               i = li;
               j = ls;
               piv = arr[(li+ls)>>1]; 
               
               while(i<=j) {

                     while(arr[i]<piv) {
                           i++;  
                     }

                     while(arr[j]>piv) {
                           j--;  
                     }

                     if(i<=j) {

                        _swap(i, j);
                        i++;j--; 
                     }
               }  

               if(li<j) _QuickSort(li, j);

               if(i<ls) _QuickSort(i, ls);
      };

      void _swap(int i, int j) {

           int x;   
               x = arr[i]^arr[j]; arr[i] = x^arr[i]; arr[j] = x^arr[j];
      } 

};

void read() {

     unsigned int elem;
 
     ifstream in(FIN);

     in>>n;

     for(int i = 1; i <= n; i++) { in>>elem;  v.pb( elem );}

     in.close();   
};

int main() {

    read();

    QuickSort q(v, n);

    q.print3(); 
 
    return(0);
}