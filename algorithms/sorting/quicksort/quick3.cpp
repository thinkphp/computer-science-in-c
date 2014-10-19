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

      //constructor of class
      QuickSort() {
      };      

      void read() {

             unsigned int elem;
 
             ifstream in(FIN);

             in>>n;

             for(int i = 1; i <= n; i++) { in>>elem;  arr.pb( elem );}

             in.close();   
      };

      void sort() {

           _QuickSort(0, n - 1);
      };

      void print() {

                freopen(FOUT, "w", stdout);

                for(vector<unsigned int>::iterator it = arr.begin(); it != arr.end() ;++it) printf("%d ", *it);

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

int main() {

    QuickSort quick;
    quick.read(); 
    quick.sort(); 
    quick.print(); 
 
   return(0);
}