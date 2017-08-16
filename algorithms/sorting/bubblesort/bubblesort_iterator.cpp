#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template <class AccessIterator>
void bubblesort(AccessIterator first, AccessIterator last) {
 
     AccessIterator i, 
                    f = first, 
                    n = last - 1;

     int finished = 0, 

         swapped;

     while( !finished ) {

             swapped = 0;

             for(i = f; i < n; ++i) {

                 if(*i > *(i+1)) {

                     swap(*i, *(i+1));

                     swapped = 1;
                 } 
             }

             if( swapped ) n--;

                    else   finished = 1;
     }        
};

typedef vector<int>::iterator I;

int main() { 

 vector<int> vec;
 int n, elem;

 ifstream fin(FIN);

 ofstream fout(FOUT);
 fin>>n;

 for(int i = 0; i < n; ++i) fin>>elem, vec.push_back(elem);

 bubblesort<I>(vec.begin(), vec.end());

 for(I it = vec.begin(); it != vec.end(); ++it) fout<<*it<<" ";

 return(0);
};
