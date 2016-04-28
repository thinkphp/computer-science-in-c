#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template <class AccessIterator>
void bubblesort(AccessIterator first, AccessIterator last) {

     AccessIterator i = first, 
                    n = last - 1;

     bool changed;
   
     do {

        changed = 1;

        for(AccessIterator it = i; it < n; ++it) {

            if(*it > *(it + 1) ) {

                swap(*it,*(it + 1));
                changed = 0;
            }  
        } 

     }while( !changed );
}

typedef vector<int>::iterator I;

typedef void (*fnPtr)(I, I);

int main() {

    int n, 

        elem;

    ifstream fin( FIN );
    ofstream fout( FOUT );

    fnPtr fn = bubblesort<I>;

    fin>>n;

    vector<int> vec; 

    for(int i = 0; i < n; ++i) fin>>elem, vec.push_back( elem );

    fn( vec.begin(), vec.end() );

    for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";

    return(0);
}