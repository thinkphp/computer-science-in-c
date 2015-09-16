#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define FIN "algsort.in"
#define FOUT "algsort.out"
#define push push_back
#define DIM 500005

class Container {

public:
      //constructor
      Container(int _N): N(_N){};

      //destructor
      ~Container(){};  

      void add_to_container(int elem) {

           vec.push( elem ); 
      };
 
      void HeapSort() {

           for(int i = 0; i < N; ++i) {

               insertHeap( vec[ i ] );
           }

           _HeapSort();
      };

      friend std::ostream &operator << (std::ostream &stream, const Container &ob) {

             for(int i = 1; i <= ob.N; ++i)  { 

                 stream<<ob.vec[ i ]<<" ";
             }
       
             return stream;
      }

private:
std::vector<int> vec;
int N;
int sizeHeap, Heap[ DIM ];

void insertHeap(int elem) {

     Heap[ ++sizeHeap ] = elem;

     up( sizeHeap ); 
}

void up(int child) {

     int parrent = child / 2;

     while( parrent ) {

            if(Heap[ parrent ] > Heap[ child ]) {

               swap(parrent, child);

               child = parrent;

               parrent = child / 2;  

            } else break; 
     }
}

void down(int parrent) {

     while( 2 * parrent <= sizeHeap ) {

            int child = 2 * parrent;

            if(2 * parrent + 1 <= sizeHeap && Heap[ 2 * parrent + 1 ] < Heap[ 2 * parrent ]) child++;

            if(Heap[ parrent ] <= Heap[ child ]) break;

            swap(parrent, child);

            parrent = child;
     } 
}

void _HeapSort() {

     for(int min, i = 1; i <= N; ++i) min = removeHeap(), vec[i] = min;
}

int removeHeap() {

    int min;

        min = Heap[ 1 ];

        Heap[ 1 ] = Heap[ sizeHeap-- ];

        down( 1 );

        return min; 
}

void swap(int i, int j) {

     int x;

         x = Heap[ i ] ^ Heap[ j ];

         Heap[ i ] = Heap[ i ] ^ x;

         Heap[ j ] = Heap[ j ] ^ x;
}

};

int main() {

    int elem, 
        n;
 
    std::ifstream fin(FIN);

    std::ofstream fout(FOUT);

    fin>>n;

    Container obj(n);   

    for(int i = 1; i <= n; ++i) {

            fin>>elem;

            obj.add_to_container( elem );
    }

    fin.close(); 

    obj.HeapSort();

    fout<<obj;

    fout.close(); 

 return(0);
};