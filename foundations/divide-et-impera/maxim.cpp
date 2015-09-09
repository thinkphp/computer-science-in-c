#include <cstdio>
#include <vector>
#define FIN "max.in"
#define FOUT "max.out"

using namespace std;

vector<int> vec;
int N;

void readData() {

     int i,a;

     freopen(FIN, "r", stdin);

     scanf("%d", &N); 
     
     for(i = 0; i < N; ++i) scanf("%d", &a), vec.push_back( a );
             
     fclose(stdin);
}

int findMax(int lo, int hi) {

     int a,
         b, 
         m;

     if(lo == hi) return vec[ lo ];

       else {

            m = (lo + hi) >> 1; 

            a = findMax(lo, m);

            b = findMax(m + 1, hi);

            if(a > b) return a;

                 else return b;            
       }
};

void writeData() {

 freopen(FOUT, "w", stdout);

 printf("\nVec -> ");

 for(int i = 0; i < N; ++i) printf("%d ", vec[ i ]);
 
 printf("\nMax -> %d ", findMax(0, N - 1));

 fclose( stdout );

}

int main() {

 readData();
 writeData();

 return(0);
};