#include <iostream>
#include <fstream>
#include <vector>
#define FIN "hashuri.in"
#define FOUT "hashuri.out"
#define ins    1
#define del    2
#define search 3
#define U 666013

using namespace std;

vector < long > Hash[ U ];

long N, 
     op, 
     x;
     ifstream fin( FIN );   
     ofstream fout( FOUT );  

//function prototypes
vector<long>::iterator seek(long val) {

       vector<long>::iterator it;

       long key = val % U;
 
       for(it = Hash[ key ].begin(); it != Hash[ key ].end(); ++it) {
 
                       if( *it == val ) {

                             return it; 
                        }
       }

       return it;
};

void insert(long val) {

     vector<long>::iterator it;

     long key;

     key = val % U; 

     it = seek( val );

     if( it == Hash[ key ].end() ) {

         Hash[ key ].push_back( val ); 
     }
};

void remove(long val) {

     vector<long>::iterator it;

     long key;

     key = val % U; 

     it = seek( val );

     if( it != Hash[ key ].end() ) {

         Hash[ key ].erase( it ); 
     }

};

void research(long val) {

     vector<long>::iterator it;

     long key;

     key = val % U; 

     it = seek( val );

     if( it != Hash[ key ].end()) fout<<"1"<<endl;

                            else  
                                  fout<<"0"<<endl;
       
};

int main() {
 
    fin>>N;    

    for(; N; --N) {

          fin>>op>>x;

          if(op == ins) {

             insert( x );

          } else if(op == del) {

             remove( x );

          } else if(op == search) {

             if(seek(x) == Hash[x%U].end()) fout<<"0\n";
                           else             fout<<"1\n"; 
          }
    } 

    fin.close();

    fout.close();

    return(0); 
}
