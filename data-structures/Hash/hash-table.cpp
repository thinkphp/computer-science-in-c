/*
7
1 3
1 20
2 7
3 4
3 20
2 20
3 20

Hash[0]:
Hash[1]:
Hash[2]:
....

*/
#include <iostream>
#include <fstream>
#include <vector>
#define FIN "hashuri.in"
#define FOUT "hashuri.out"
#define MOD 100000 //value = 9 atunci hash[ 2 ].push_back(9)
                   //
#define ins 1
#define del 2
#define search_op 3

using namespace std;

//Hash Table Data Structure
vector< long > Hash[ MOD ];
//Hash [
//     0[value1, ]
//     1[value2, ]
//     2[value3, ]
//     3[value4, ]
//      ......
//     188[188]

//   ]
// Hash [ [] [] [] [3] [4] ]
// 188
// Hash[ key ].push_back( VALUE )

// Hash[ 0 ].push_back( 16 )
// Hash[ 3 ].push_back( 11 )
// Hash[ 3 ].push_back( 27 )
// Hash[ 3 ].push_back( 19 )
// Hash[ 3 ].push_back( 11,28,19 )
//Hash.insert(Hash.end(), { 11, 28, 19} );


ifstream fin(FIN);
ofstream fout(FOUT);
//Multimea noastra : 3, 20, 101, 21
// Hash[3]: 3
// Hash[20]: 20
// Hash[21]: 21
// Hash[101]: 101
//
//                                 3

vector<long>::iterator seek(long value) {

     vector<long>::iterator it;
     // key = 3 % 100000
     long key = value % MOD;//f( value ) = value % MOD = KEY
              //hash[3].begin()
     for(it = Hash[ key ].begin(); it != Hash[ key ].end(); it++) {

         if(*it == value) return it;
     }
     return Hash[ key ].end();
}
//                 value = 3
//Multime = {1,2,3,4,5,6}
void insert(long value) {

    vector<long>::iterator it;

    it = seek( value );
    //it = Hash[key].end()
    // it = un pointer catre un element din multime
     //value = 7
     //key = 7 =>
    long key = value % MOD;

    if( it == Hash[key].end() ) Hash[ key ].push_back( value );
}

int search(long value) {

    vector<long>::iterator it;

    long key = value % MOD;

    it = seek( value );

    if(it != Hash[key].end()) return 1;

          else
                              return 0;
}

void remove(long value) {

     vector<long>::iterator it;

     long key = value % MOD;

     it = seek( value );

     if( it != Hash[ key ].end() ) Hash[ key ].erase( it );
}

int research(long value) {

    vector<long>::iterator it;

    long key = value % MOD;

    it = seek( value );

    if( it != Hash[ key ].end() ) return 1;

                else
                                  return 0;
}
int main(int argc, char const *argv[]) {

    int N; //numarul de operatii
    int op,
        el;

    //Hash[0].push_back(11);
    //Hash[0].push_back(28);
    //Hash[0].push_back(19);
    //Hash[0].insert(Hash[0].end(), { 11, 28, 19} );

    //for(vector<long>::iterator it = Hash[0].begin(); it != Hash[0].end(); it++) {
        //cout<<*it<<" ";
    //}
    fin>>N;//daca N = 3 citit din fisier
    /*
    while(N) {
      //executa instructiunea
      N--
    }

    for( ; N; N--) {
      //3 != 0
      //executa instructiunea
      //N = N - 1= 3 -1 = 2
      //N = 2
      //N != 0? adica 2 != 0: da
      //executa instructiunea
      //N = N - 1; N = 1
      //N != 0? 1 != 0: da
      //executa
      //N = N - 1 => N = 0
    }

    while(N--) {

    }
    */

    for( ;N; N--) {

        fin>>op>>el;//citim operatia si elementul multimii

        if( op == ins ) {

            //insert(3)
            insert( el  );

        } else if(op == del) {

            remove( el );

        } else if( op == search_op ) {

             int ans = research( el );

             if(ans == 1) fout<<"1\n";

                   else
                          fout<<"0\n";
        }
    }

    return 0;
}
/*
MOD = 10

Multimea = {4,5,7,9,20,32,53,55,60,100}

value = 4
key = value % MOD; 4 % 10 = 4
value = 5
key = value % MOD; 5 % 10 = 5
value = 7
key = value % MOD; 7 % 10 = 7
value = 9
key = value % MOD; 9 % 10 = 9
value = 20
key = value % MOD; 20 % 10 = 0
value = 32
key = value % MOD; 32 % 10 = 2
value = 53
key = value % MOD; 53 % 10 = 3
value = 55
key = value % MOD; 55 % 10 = 5
value = 60
key = value % MOD; 60 % 10 = 0
value = 100
key = value % MOD; 100 % 10 = 0

vector<long>::iterator seek(long value) {

     vector<long>::iterator it;
     // key = value % 10
     long key = value % MOD;//f( value ) = value % MOD = KEY
              //hash[3].begin()
     for(it = Hash[ key ].begin(); it != Hash[ key ].end(); it++) {

         if(*it == value) return it;
     }
     return Hash[ key ].end();
}


HashTable [
          key0[0]: 20,60,100
          key1[]
          key2[2]: 32
          key3[3]: 53
          key4[4] : 4
          key5[5] : 5,55
          key7[7] : 7
]         key9[9] : 9


if(it != Hash[ key ].end() ) Hash[ key ].erase( it );

*/
