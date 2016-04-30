#include <iostream>
#include <fstream>
/** 
 * Cocktail.cpp 
 * Method Sorting: Cocktail Technique
 * Author        : Adrian Statescu <http://adrianstatescu.com>
 */
#include <vector>
#include <algorithm>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template <class AccessIterator>
void bubblesort(AccessIterator first, AccessIterator last) {

     AccessIterator it, 

                    begin = first,

                    n = last - 1;

     bool changed = false;

     int finished = 0;

     while( !finished ) {

             changed = false;

             for(it = begin; it < n; ++it) {

                 if( *it > *(it + 1) ) {

                     swap(*it, *(it + 1) );

                     changed = true;
                 }    
             }

             if( changed ) n--;

                 else 
                           finished = 1;


             if( !finished ) {

                 changed = false;


              for(it = n; it > begin; --it) {

                 if( *it < *(it - 1) ) {

                     swap(*it, *(it - 1) );

                     changed = true;
                 }    
              }

             if( changed ) begin++;

                 else 
                           finished = 1;
          

             } 
     } 
}

typedef vector<int>::iterator I;

typedef void (*fnPtr)(I, I);

int main() {

    int n, 

        elem;

    ifstream fin( FIN );

    ofstream fout( FOUT );

    fnPtr sort = bubblesort<I>;

    fin>>n;

    vector<int> vec; 

    for(int i = 0; i < n; ++i) fin>>elem, vec.push_back( elem );

    sort( vec.begin(), vec.end() );

    for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";

    return(0);
}