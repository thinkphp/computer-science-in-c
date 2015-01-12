#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

void _mergesort(vector<int> &vec, int left, int right) {

     if(left == right) return;

     else {

         int middle = (left + right) >> 1;

         _mergesort(vec, left, middle);    

         _mergesort(vec, middle + 1, right);

         int i = left,

             j = middle + 1;

          vector<int> newvec;

          while(i <= middle && j <= right) {

                if(vec[ i ] <= vec[ j ]) {

                   newvec.push_back(vec[ i++ ]);

                } else {

                   newvec.push_back(vec[ j++ ]);
                }
          } 

          while(i <= middle) {

                   newvec.push_back(vec[ i++ ]);       
          } 

          while(j <= right) {

                   newvec.push_back(vec[ j++ ]);
          } 

          for(i = left; i <= right; i++) {

              vec[ i ] = newvec[ i - left ];
          } 
     }   
};

void sort(vector<int> &vec) {

     _mergesort(vec, 0, vec.size() - 1); 
}; 

void write(vector<int> vec) {
 
     ofstream fout( FOUT );

     for(int i = 0; i < vec.size(); i++) fout<<vec[ i ]<<" ";

     fout.close();
};

int main() {

    vector<int> vec;

    int N, 

        elem;

     ifstream fin( FIN );

     fin>>N; 

     for(int i = 0; i < N; i++) fin>>elem
                                ,
                                vec.push_back( elem );

     fin.close();
     
     sort( vec );

     write( vec );               
 
    return(0);         
};