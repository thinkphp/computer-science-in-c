#include <iostream>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template <class AccessIterator>
void bubblesort(AccessIterator first, AccessIterator last) {

     AccessIterator it, 

                    end = last - 1;
     
     bool finished = false, 

          swapped = true;

     while( swapped ) {

           swapped = false;

           for(it = first; it != end; ++it) {

               if( *it > *(it+1)) {

                    swap(*it, *(it+1));
  
                    swapped = true;
               }
           } 

     }
     
};

int main() {

    ifstream fin(FIN);

    ofstream fout(FOUT);

    typedef vector<int>::iterator I;

    typedef void (*ptrFunc)(I, I); 

    ptrFunc fn = bubblesort<I>;  

    vector<int> vec;

    int n, elem;

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>elem, vec.push_back(elem);

    fn(vec.begin(), vec.end()); 

    for(auto &v : vec) fout<<v<<" "; 

    return(0);
};