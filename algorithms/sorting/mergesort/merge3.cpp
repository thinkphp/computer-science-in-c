#include <cstdio>
#include <fstream>
#include <vector>
#define FIN "algsort.in"
#define FOUT "algsort.out"

using namespace std;

vector<int> vec;
int n;

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


int mergesort(int li, int ls) {

    if(li == ls) return vec[ li ];

    else {

         int m = (li+ls)>>1; 

         mergesort(li, m);

         mergesort(m + 1, ls);
     
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

void sort() {

     mergesort(0, n - 1);

};

int main() {

    read(); 
    sort();
    write();

    return(0); 
}
