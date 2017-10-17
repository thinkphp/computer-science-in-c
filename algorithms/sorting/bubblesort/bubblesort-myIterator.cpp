#include <iostream>
#include <fstream>
#include <vector>
#define push push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template<class Type>
void bubblesort(Type first, Type last) {

     bool swapped, 
          finished = false;
     Type start, 
          end = last - 1;
      
     while( !finished ) {
     
             swapped = false;

             for(start = first; start != end; ++start) {

                 if(*start > *(start+1)) {

                    swap(*start, *(start+1));
                    swapped = true;
                 }   
             }

             if(swapped) last--;
                     else finished = true;
     }     
};

typedef vector<int>::iterator I;

int main() {

    ifstream fin(FIN);

    ifstream fin(FOUT);

    vector<int> vec;

    typedef void (*ptrFun)(I,I); 

    ptrFun sort = bubblesort<I>; 

    int n, 

        elem;

    fin>>n;

    for(int i = 0; i < n; ++i) fin>>elem,vec.push(elem);

    sort(vec.begin(), vec.end());

    for(I i = vec.begin(); i != vec.end(); ++i) cout<<(*i)<<" ";

 return(0);
};