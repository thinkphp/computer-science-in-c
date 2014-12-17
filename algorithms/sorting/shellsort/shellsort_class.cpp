/**
 *
 *  Author     : Adrian Statescu <mergesortv@gmail.com>.
 *  Decription : Shell Sort for 100points.
 *  License    : Free to use and distribute as long as this note is kept.
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#define pb push_back
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef unsigned int uint;

using namespace std;

class Sort {

      public:
      vector<uint> vect;
      uint n;
     
void read() {

     uint elem;

     ifstream fin( FIN );

     fin>>n;

     for(uint i = 0; i < n; i++) fin>>elem, vect.pb( elem );
                                 
     fin.close(); 
};

void write() {

     ofstream fout( FOUT );

     ostream_iterator<uint> os_it(fout, " ");

     copy(vect.begin(), vect.end(), os_it);     

     fout.close(); 
};

void shell() {

      int h = 1, 
          i, 
          j, 
          aux;

     do {

       h = 3 * h + 1; 

     } while( h <= n);

     do {

        h /= 3;

        for(i = h; i < n; i++) {

            aux = vect[ i ];

            for(j = i - h; j >= 0 && vect[ j ] > aux; j -= h) {

                vect[ j + h ] = vect[ j ]; 
            } 

                vect[ j + h ] = aux;
        } 

     } while( h > 1);
};

}; //end class

int main() {

    Sort shell;

    shell.read();
    shell.shell();
    shell.write(); 

    return(0); 
};
