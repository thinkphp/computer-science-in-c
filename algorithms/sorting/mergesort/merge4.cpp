#include <cstdio>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

class MergeSort {

public:
vector<int> vec;
int n;

MergeSort() {

    read();
    doit();
    write(); 
}

void doit() {

     _MergeSort(0, n - 1);     
}

void read() {

     int elem;

     ifstream cin(FIN);

     cin>>n; 
      
     for(int i = 0; i < n; i++) cin>>elem, vec.push_back( elem );

     cin.close(); 
}

void write() {

     ofstream cout(FOUT);
      
     for(int i = 0; i < n; i++) cout<<vec.at( i )<<" ";

     cout.close(); 
}


private:

int _MergeSort(int li, int ls) {

    if(li == ls) return vec[ li ];

    else {

         int m = (li+ls)>>1; 

         _MergeSort(li, m);

         _MergeSort(m + 1, ls);
     
         int i = li, j = m + 1, k = 0;

         vector<int> aux;

         while(i<=m && j <= ls) {

               if(vec[i] < vec[j]) aux.push_back(vec[i++]);

                           else    aux.push_back(vec[j++]);
         }

         while(i<=m) aux.push_back(vec[i++]);

         while(j<=ls) aux.push_back(vec[j++]);

         k = 0; 

         for(int r = li; r <= ls; r++) {

             vec[ r ] = aux[ k++ ];  
         }          
    } 
}

};

int main() {

    MergeSort merge;

    return(0); 
}
