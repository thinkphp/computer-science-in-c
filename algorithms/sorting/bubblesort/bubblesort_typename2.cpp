/**
 *  BubbleSort
 *  ----------
 *  Advatages: 
 *       - stable
 *       - in-place
 *
 *  Disadvantages:
 *       - slow for large data set
 *
 *  Time Complexity:
 *       -worst-case   performance O(n^2) 
 *       -avarage-case performance O(n^2)
 *       -best-case    performance O(n)
 *
 *  Space Complexity:
 *       - O(1)
 */
#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using std::vector;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

template<typename T>
void print(vector<T> l) {

     int i, 
         n = l.size();

     for(i = 0; i < n; ++i) {

         cout<<l[i]<<" "; 
     }

     cout<<endl;
};

template<typename T>
void bubblesort(vector<T>& v) {

     bool finished = 0, 
          swapped; 
     int  last = v.size();
     
     while(!finished) {

            swapped = false;

            for(int i = 0; i < last - 1; ++i) {

                if(v[i] > v[i+1]) {

                   T aux = v[i];
                     v[i] = v[i+1];
                     v[i+1] = aux;
                     swapped = true;   
                }
            } 

            if( swapped ) last--;
                else      finished = true; 
     }
};


template<typename T>
vector<T> _bubblesort(vector<T> l) {

     vector<T> copy = l;

     bool finished = 0, 

          swapped; 

     int  last = copy.size();


     
     while(!finished) {

            swapped = false;

            for(int i = 0; i < last - 1; ++i) {

                if(copy[i] > copy[i+1]) {

                   T aux = copy[i];
                     copy[i] = copy[i+1];
                     copy[i+1] = aux;
                     swapped = true;   
                }
            } 

            if( swapped ) last--;

                else      

                          finished = true; 
     }

     return copy;
};

int main() {

 int elem, n;
 ifstream fin(FIN);
 vector<int> v;

 fin>>n;
 for(int i = 0; i < n; ++i) fin>>elem, v.pb(elem);

 v = _bubblesort(v);

 print(v);

 return(0);
};