#include <iostream>
#include <fstream>
/** 
 * selectionbymin.cpp 
 * Method Sorting: Selection Technique
 * Author        : Adrian Statescu <http://adrianstatescu.com>
 */
#include <vector>
#include <algorithm>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

template <class AccessIterator>
void selection(AccessIterator first, AccessIterator last) {

               AccessIterator begin = first, 

                              min; 

               while( begin < last ) {

                      min = begin;

                      for( AccessIterator it = begin; it < last; ++it ) {

                          if( *it < *min ) {

                               min = it;
                          } 
                      }

                      swap( *min, *begin );

                      begin++; 
                }
}

typedef vector<int>::iterator I;

typedef void (*fnPtr)(I, I);

int main() {

    int n, 

        elem;

    ifstream fin( FIN );

    ofstream fout( FOUT );

    fnPtr sort = selection<I>;

    fin>>n;

    vector<int> vec; 

    for(int i = 0; i < n; ++i) fin>>elem, vec.push_back( elem );

    sort( vec.begin(), vec.end() );

    for(int i = 0; i < n; ++i) fout<<vec[ i ]<<" ";

    return(0);
}